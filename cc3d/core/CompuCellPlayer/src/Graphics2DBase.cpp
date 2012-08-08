#include "Graphics2DBase.h"
// #include <qpainter.h>


// #include <qpainter.h>
// #include <qpen.h>


#include "Projection2DData.h"
#include "UniversalGraphicsSettings.h"
#include <cmath>

#include <iostream>
#include "contourlines.h"
#include <Utils/Coordinates3D.h>
#include <limits>


using namespace std;

Graphics2DBase::Graphics2DBase( const char *name): GraphicsBase()
{
   painterPtr=0;
   painterPtr=new QPainter();
   imageFormat=QImage::Format_RGB32;

   double sqrt_3_3=sqrt(3.0)/3.0;
   hexagon.push_back( QPointF(0. , sqrt_3_3 ));
   hexagon.push_back( QPointF(0.5 , 0.5*sqrt_3_3));
   hexagon.push_back( QPointF(0.5, -0.5*sqrt_3_3));
   hexagon.push_back( QPointF(0. , -sqrt_3_3));
   hexagon.push_back( QPointF(-0.5 , -0.5*sqrt_3_3));
   hexagon.push_back( QPointF(-0.5, 0.5*sqrt_3_3));
   //Hex borders
   bordersHex.push_back(QLineF(hexagon[0],hexagon[1]));
   bordersHex.push_back(QLineF(hexagon[1],hexagon[2]));
   bordersHex.push_back(QLineF(hexagon[2],hexagon[3]));
   bordersHex.push_back(QLineF(hexagon[3],hexagon[4]));
   bordersHex.push_back(QLineF(hexagon[4],hexagon[5]));
   bordersHex.push_back(QLineF(hexagon[5],hexagon[0]));

   

} 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Graphics2DBase::~Graphics2DBase(){
   if(painterPtr) delete painterPtr;painterPtr=0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::produceImage(QImage & image){
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::preDrawTask(){

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::postDrawTask(){

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::initPainter(){

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintBackground(const QColor & _color){

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintConcentrationLattice(){

   std::map<unsigned short,QPen> & typePenMap = univGraphSetPtr->typePenMap;


   QColor c(0,0,0);

   QBrush colormapBrush(c);///have to initialize brush with some color otherwise setColor seems not to work
   QPen colormapPen;
   QPen *penPtr;
//   QBrush *brushPtr;
   std::map<unsigned short,QPen>::iterator pos;
   std::map<unsigned short,QBrush>::iterator posBrush;



   maxConcentrationTrue=(numeric_limits<float>::min)();
   minConcentrationTrue=(numeric_limits<float>::max)();

   //bool minInitialized=false;

   ///adding legend size
   
   if(legendEnable){
      labelSize=QSize(projData.sizeL ,projData.sizeM+legendWidth);
   }else{
      labelSize=QSize(projData.sizeL ,projData.sizeM);
   }
   labelSize*=(double)univGraphSetPtr->zoomFactor;

//    cerr<<"projData.sizeL="<<projData.sizeL<<" projData.sizeM="<<projData.sizeM<<endl;
//     cerr<<"labelSize="<<labelSize.width()<< " "<<labelSize.height()<<endl;

      preDrawTask();

   
   if(painterPtr->isActive() ){
      painterPtr->end(); ///ending active painter
   }

//    painterPtr->begin(pixmap());
    initPainter();

//    cerr<<"PAINTER STARTED CONCENTRATION LATTICE"<<endl;
//    cerr<<"projData.xMin="<<projData.xMin<<" projData.xMax="<<projData.xMax<<endl;
//    cerr<<"projData.yMin="<<projData.yMin<<" projData.yMax="<<projData.yMax<<endl;
//    cerr<<"projData.zMin="<<projData.zMin<<" projData.zMax="<<projData.zMax<<endl;

   pos=typePenMap.find(0);
   penPtr=&(pos->second);

   paintBackground(penPtr->color());



   if(!currentConcentrationFieldPtr){
      cerr<<"currentConcentrationFieldPtr is null"<<endl;
      return;
   }

   floatField3D_t & concentrationField = *currentConcentrationFieldPtr;

   for(unsigned int x = projData.xMin ; x < projData.xMax  ; ++x)
      for(unsigned int y = projData.yMin ; y < projData.yMax ; ++y)
         for(unsigned int z = projData.zMin ; z < projData.zMax ; ++z){


            if(concentrationField[x][y][z]>maxConcentrationTrue){
               maxConcentrationTrue=concentrationField[x][y][z];
            }

            if(concentrationField[x][y][z]<minConcentrationTrue){
               minConcentrationTrue=concentrationField[x][y][z];
            }

         }

//    cerr<<"minConcentration="<<minConcentrationTrue<<" maxConcentration="<<maxConcentrationTrue<<endl;

   ///setting up % threshold for concentration

   if(!maxConcentrationFixed){
      maxConcentration = maxConcentrationTrue;
   }
   if(!minConcentrationFixed){
      minConcentration = minConcentrationTrue;
   }

   cerr<<"minConcentration="<<minConcentration<<" maxConcentration="<<maxConcentration<<endl;
   float percentage;
   for(unsigned int x = projData.xMin ; x < projData.xMax  ; ++x)
      for(unsigned int y = projData.yMin ; y < projData.yMax ; ++y)
         for(unsigned int z = projData.zMin ; z < projData.zMax ; ++z){


//             if(concentrationField[x][y][z]<=0){
//                c.setHsv( 255, 255,0);
//             }else
            {
               percentage=percentageQuantity(
                           concentrationField[x][y][z],
                           minConcentration/*-fabs(minConcentration*0.02)*/,
                           maxConcentration/*+fabs(maxConcentration*0.02)*/
                           );
               
                if(percentage<0.0)
                   percentage=0.0;
                if(percentage>1.0)
                  percentage=1.0;
                if(percentage!=percentage){//perentage is nan - this happens e.g. when min and max concentrations are the same
                     percentage=0.0; // will set percentage to zero
                }
// 		  cerr<<"minConcentration="<<minConcentration<<" maxConcentration="<<maxConcentration<<"percentage="<<percentage<<endl;
                  c.setHsv( (int)((1.0-percentage)*255), 255,255 );

//                if(percentage==0.0)
//                   c.setHsv(255, 255,255 );
                  
//                if(percentage<0.0)
//                   c.setHsv( -1, 0,0 );

                              
               if(percentage==0.0)
                  c.setHsv( -1, 0,0 );
           }


            painterPtr->setPen(*penPtr);
            colormapBrush.setColor(c);
            painterPtr->setPen(*&univGraphSetPtr->borderPen);///borderline
            painterPtr->setBrush(colormapBrush);///rectangle fill color

         if(projData.projection=="xy"){
            paintPixelXY(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
            continue;
         }

         if(projData.projection=="xz"){
            paintPixelXZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
            continue;
         }

         if(projData.projection=="yz"){
            paintPixelYZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
            continue;
         }


   }
   if(univGraphSetPtr->contoursOn){
      doContourLines();
   }

   painterPtr->end();
   ///painting legend
   if(legendEnable){
      paintLegend(minConcentration,maxConcentration,"d","colormap");
   }

      postDrawTask();


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintLegend(float _min, float _max,std::string location,std::string type){
 
 unsigned int rectWidth;
   unsigned int rectHeight;
   
   QColor c(0,0,0);
   
   unsigned int numberOfRectangles = legendDimension( location , rectWidth, rectHeight, type );

 
    
//    cerr<<"begin legend"<<endl;
//    cerr<<"numberOfRectangles="<<numberOfRectangles<<endl;
   
   if(!numberOfRectangles){
      return;
   }
   
   if(painterPtr->isActive() ){
      painterPtr->end(); ///ending active painter
   }
   
//    painterPtr->begin(pixmap());
    initPainter();


   ///drawing legend - colormap

   
   unsigned int maxNumberOfExtraPixels=projData.sizeL*univGraphSetPtr->zoomFactor-numberOfRectangles*rectWidth;
   unsigned int extraPixelCounter=0;
//     cerr<<"maxNumberOfExtraPixels="<<maxNumberOfExtraPixels<<endl;
   unsigned int extraWidth=0;
   float percentage;
   unsigned int numAcc;
   
   if(maxNumberOfExtraPixels){
        extraWidth=1; 
   }

   if(type=="colormap"){
      numAcc=numberAccuracy;
   }
   
   if(type=="vector"){
      numAcc=numberAccuracyVector;
   }

   
   for(unsigned int i = 0 ; i < numberOfRectangles ; ++i){
   
      percentage = percentageQuantity((i*(_max-_min))/(numberOfRectangles-1)+_min,_min,_max);

      if(percentage!=percentage){//perentage is nan - this happens e.g. when min and max concentrations are the same
         percentage=0.0; // will set percentage to zero
      }

      c.setHsv( (int)((1.0-percentage)*255), 255,255 );

//       cerr<<"i*rectWidth+extraPixelCounter="<<i*rectWidth+extraPixelCounter<<" rectWidth+extraPixelCounter="<<rectWidth+extraPixelCounter<<
//        " rectHeight="<<rectHeight<<" rectWidth="<<rectWidth<<endl;

      painterPtr->fillRect(i*rectWidth+extraPixelCounter,projData.sizeM*univGraphSetPtr->zoomFactor,
                                    rectWidth+extraWidth, rectHeight, QBrush(c));
                                    
      painterPtr->setPen(QPen("white"));

//       if(silentMode &&xServerFlag){//setting font in the non-GUI , silent mode but with established connection to X-Server
//          QFont legendFont("Times",12);
//          painterPtr->setFont(legendFont);
//       }
//       cerr<<"silentMode="<<silentMode<<" xServerFlag="<<xServerFlag<<endl;
      if(xServerFlag){//Qt 4.2 as of 07/2007 does not permit to draw text without connecting to X-server - that's why there is no text in the silent mode
      //instead we output a file with max and min values of the plotted quantity (either concentratino or vector magnitude)
         painterPtr->drawText(
                                       (i+0.1)*rectWidth+extraPixelCounter,
                                       (projData.sizeM+(int)(0.75*legendWidth))*univGraphSetPtr->zoomFactor,
                                       QString().setNum(_min+i*(_max-_min)/(numberOfRectangles-1),'g',numAcc)
                                       );
      }

      if(extraPixelCounter<maxNumberOfExtraPixels){
         ++extraPixelCounter;
      }else{
         extraWidth=0; 
      }
      
   }

   painterPtr->end();


// exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Graphics2DBase::legendDimension(std::string location, unsigned int &rectWidth,unsigned int & rectHeight,std::string type){
   unsigned int minRectWidth=8;
   unsigned int minNumberOfRect=5;
   unsigned int numberOfRect;
   
   if(location=="l"){///right
      numberOfRect=projData.sizeM/minRectWidth;
   }
   else if(location=="d"){///down
      numberOfRect=projData.sizeL/minRectWidth;
   }
   else{
      return 0;
   }
   
   if(type=="colormap"){
      numberOfRect=numberOfLegendBoxes;
     
   }
   if(type=="vector"){
   
      numberOfRect=numberOfLegendBoxesVector;
      
   }
   
//    if(numberOfRect<minNumberOfRect)
//       return 0;

   if(location=="l"){///right
      rectWidth=(legendWidth/2)*univGraphSetPtr->zoomFactor;
      rectHeight=projData.sizeM*univGraphSetPtr->zoomFactor/numberOfRect;
      return numberOfRect;
   }

   if(location=="d"){///right
      rectWidth=projData.sizeL*univGraphSetPtr->zoomFactor/numberOfRect;
      rectHeight=(legendWidth/2)*univGraphSetPtr->zoomFactor;
      return numberOfRect;
   }

   return 0;  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintCellVectorFieldLatticeCore(bool _erasePrevious){
   std::map<unsigned short,QPen> & typePenMap = univGraphSetPtr->typePenMap;


//    std::map<CompuCell3D::CellG* ,VectorFieldPlotItem > mapCellToVectorFieldPlotItem;
//    std::map<CompuCell3D::CellG* ,VectorFieldPlotItem >::iterator mitr;

   std::map<int ,VectorFieldPlotItem > mapCellToVectorFieldPlotItem; //cell id to VectorFieldPlotItem map
   std::map<int ,VectorFieldPlotItem >::iterator mitr;//cell id to VectorFieldPlotItem map iterator

   std::map<int,CompuCell3D::CellG*> idToCellMap;//mapping cell id's to CellG*
   std::map<int,CompuCell3D::CellG*>::iterator mitrIdToCell;

   GraphicsDataFields::vectorFieldCellLevel_t::iterator vitr;

   for(vitr=currentVectorCellLevelFieldPtr->begin() ; vitr != currentVectorCellLevelFieldPtr->end() ; ++vitr){
      idToCellMap.insert(make_pair(vitr->first->id,vitr->first));
   }
   
//    for (mitrIdToCell=idToCellMap.begin() ; mitrIdToCell!=idToCellMap.end() ; ++mitrIdToCell){
//       cerr<<mitrIdToCell->first<<" "<<mitrIdToCell->second<<endl;
// 
//    }

   
   QColor c(0,0,0);

   QBrush colormapBrush(c);///have to initialize brush with some color otherwise setColor seems not to work
   QPen colormapPen;
   QPen *penPtr;
//   QBrush *brushPtr;
   std::map<unsigned short,QPen>::iterator pos;
   std::map<unsigned short,QBrush>::iterator posBrush;


   maxMagnitudeTrue=(numeric_limits<float>::min)();
   minMagnitudeTrue=(numeric_limits<float>::max)();   

   
   if(painterPtr->isActive() ){
      painterPtr->end(); ///ending active painter
   }

//    painterPtr->begin(pixmap());
   initPainter();


      pos=typePenMap.find(0);
      penPtr=&(pos->second);
   //    pixmap()->fill(penPtr->color());
   //    pixmap2D.fill(penPtr->color());
   if(_erasePrevious){
      paintBackground(penPtr->color());
   }
//    if(!currentVectorCellFieldPtr){
//       cerr<<"currentVectorCellFieldPtr is null"<<endl;
//       return;
//    }
   
   vectorCellFloatField3D_t & vectorCellField =  *currentVectorCellFieldPtr;
   field3DGraphicsData_t & field3DGraphicsData  = graphFieldsPtr->field3DGraphicsData;

   float vX,vY,vZ;
   double magnitude2DSq;
   double magnitude2D;

   CompuCell3D::CellG * cell;

   Coordinates3D<float> *v;
   cerr<<"before entering the loop"<<endl;
   cerr<<"projData.projection="<<projData.projection<<endl;
   for(unsigned int x = projData.xMin ; x < projData.xMax  ; ++x)
      for(unsigned int y = projData.yMin ; y < projData.yMax ; ++y)
         for(unsigned int z = projData.zMin ; z < projData.zMax ; ++z){
//           Coordinates3D<float> & v=vectorCellField[x][y][z].first;
//           
//           vX=v.X();
//           vY=v.Y();
//           vZ=v.Z();

         
          //here I will calculate 2D CM's of each cell  - this will be used to draw cell vector field
//           cerr<<"field3DGraphicsData[x][y][z].type="<<field3DGraphicsData[x][y][z].type<<endl;
          if(!field3DGraphicsData[x][y][z].type){//skip medium
            continue;
          }
          
//           if(univGraphSetPtr->avoidType(vectorCellField[x][y][z].second->type)){//skip medium
//             continue;
//           }
          
//           mitr = mapCellToVectorFieldPlotItem.find(vectorCellField[x][y][z].second); //vectorCellField[x][y][z].second - is CellG*
          mitr = mapCellToVectorFieldPlotItem.find(field3DGraphicsData[x][y][z].id); //vectorCellField[x][y][z].second - is CellG*
         mitrIdToCell=idToCellMap.find(field3DGraphicsData[x][y][z].id);
/*         cerr<<"field3DGraphicsData[x][y][z].type="<<field3DGraphicsData[x][y][z].type<<endl;
         cerr<<"mitrIdToCell != idToCellMap.end()="<<(mitrIdToCell != idToCellMap.end())<<endl;*/
         if(mitrIdToCell != idToCellMap.end()){
         
            cell=mitrIdToCell->second;
            vitr=currentVectorCellLevelFieldPtr->find(cell);
            v=&vitr->second;



            vX=v->x;
            vY=v->y;
            vZ=v->z;
//             cerr<<"vX="<<vX<<" vY="<<vY<<" magnitude2D="<<magnitude2D<<endl;
         }else{
            continue; //means given cell of id field3DGraphicsData[x][y][z].id has no vector assigned
         }

//calculating 2D centroids of cells             
//           if(mitr != mapCellToVectorFieldPlotItem.end() ){
//             mitr->second.CM+=Coordinates3D<int>(x,y,z);
//             ++(mitr->second.dimVolume);//increasing 2D surface
//             mitr->second.vectorQuant=v;
//           }else{
//             
//             mapCellToVectorFieldPlotItem.insert(make_pair(vectorCellField[x][y][z].second ,
//             VectorFieldPlotItem(Coordinates3D<int>(x,y,z),1 ,v ) ) );
// 
//           }

//picking last point belonging to a cell to anchor the arrow
          if(mitr != mapCellToVectorFieldPlotItem.end() ){
            mitr->second.CM=Coordinates3D<int>(x,y,z);
            ++(mitr->second.dimVolume);//increasing 2D surface
            mitr->second.vectorQuant=*v;
          }else{

            mapCellToVectorFieldPlotItem.insert(make_pair(field3DGraphicsData[x][y][z].id ,
            VectorFieldPlotItem(Coordinates3D<int>(x,y,z),1 ,*v ) ) );

          }

          
          if(projData.projection=="xy"){
            magnitude2DSq=vX*vX+vY*vY;

          }

          if(projData.projection=="xz"){
            magnitude2DSq=vX*vX+vZ*vZ;
          }

          if(projData.projection=="yz"){
            magnitude2DSq=vY*vY+vZ*vZ;
          }

          magnitude2D=sqrt(magnitude2DSq);
//           cerr<<"vX="<<vX<<" vY="<<vY<<" magnitude2D="<<magnitude2D<<endl;

          
          if(magnitude2D>maxMagnitudeTrue){
            maxMagnitudeTrue=magnitude2D;
         }

            if(magnitude2D<minMagnitudeTrue){
               minMagnitudeTrue=magnitude2D;
               //cerr<<"minMagnitudeTrue="<<minMagnitudeTrue<<endl;
            }

         }

   cerr<<"minMagnitude="<<minMagnitudeTrue<<" maxMagnitude="<<maxMagnitudeTrue<<endl;

   ///setting up % threshold for concentration
   
   if(!maxMagnitudeFixed){
      maxMagnitude = maxMagnitudeTrue;
   }
   if(!minMagnitudeFixed){
      minMagnitude = minMagnitudeTrue;
   }
   
   float percentage;
   if(_erasePrevious){
      for(unsigned int x = projData.xMin ; x < projData.xMax  ; ++x)
         for(unsigned int y = projData.yMin ; y < projData.yMax ; ++y)
            for(unsigned int z = projData.zMin ; z < projData.zMax ; ++z){
   //          Coordinates3D<float> & v=vectorCellField[x][y][z].first;
            
               c.setHsv( -1, 0,0 );
               painterPtr->setPen(*penPtr);
               colormapBrush.setColor(c);
               painterPtr->setPen(*&univGraphSetPtr->borderPen);///borderline
               painterPtr->setBrush(colormapBrush);///rectangle fill color
   
            if(projData.projection=="xy"){
               paintPixelXY(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               continue;
            }
   
            if(projData.projection=="xz"){
               paintPixelXZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               continue;
            }
   
            if(projData.projection=="yz"){
               paintPixelYZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               continue;
            }
   
   
      }
   }
//    painterPtr->end();
//    setPixmap(pixmap2D);
//    update();
//    return;

   float xCM,yCM,zCM;
   
   QPen pen;
   QBrush brush(Qt::yellow,Qt::SolidPattern);
   //drawing arrows
   pen.setColor(Qt::yellow);
      

   painterPtr->setPen(pen);
   painterPtr->setBrush(brush);

   for(mitr = mapCellToVectorFieldPlotItem.begin() ; mitr != mapCellToVectorFieldPlotItem.end() ; ++mitr){
//calculating center of area to get anchor point for the arrow   
//       xCM=mitr->second.CM.X()/((float)mitr->second.dimVolume);
//       yCM=mitr->second.CM.Y()/((float)mitr->second.dimVolume);
//       zCM=mitr->second.CM.Z()/((float)mitr->second.dimVolume);

//simpler algorithm
      xCM=mitr->second.CM.X();
      yCM=mitr->second.CM.Y();
      zCM=mitr->second.CM.Z();
      
      Coordinates3D<float> & v=mitr->second.vectorQuant;

      vX=v.X();
      vY=v.Y();
      vZ=v.Z();

      if(projData.projection=="xy"){
         magnitude2D=sqrt(vX*vX+vY*vY);
         percentage=percentageQuantity(magnitude2D,minMagnitude,maxMagnitude);
            if(percentage<0.0)
               percentage=0.0;
            if(percentage>1.0)
               percentage=1.0;
            if(percentage!=percentage){//perentage is nan - this happens e.g. when min and max concentrations are the same
               percentage=0.0; // will set percentage to zero
            }

         c.setHsv( (int)((1.0-percentage)*255), 255,255 );
         pen.setColor(c);
         brush.setColor(c);
         painterPtr->setPen(pen);
         painterPtr->setBrush(brush);
         if(scaleArrows){
            if(fixedArrowColorFlag){
               pen.setColor(univGraphSetPtr->arrowPen.color());
               brush.setColor(univGraphSetPtr->arrowPen.color());
               painterPtr->setPen(pen);
               painterPtr->setBrush(brush);
            }

            drawArrow((int)xCM,(int)yCM,vX,vY,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr,arrowLength*percentage);
         }else{
            drawArrow((int)xCM,(int)yCM,vX,vY,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr);
         }
         continue;
      }

      if(projData.projection=="xz"){
         magnitude2D=sqrt(vX*vX+vZ*vZ);
         percentage=percentageQuantity(magnitude2D,minMagnitude,maxMagnitude);
            if(percentage<0.0)
               percentage=0.0;
            if(percentage>1.0)
               percentage=1.0;
            if(percentage!=percentage){//perentage is nan - this happens e.g. when min and max concentrations are the same
                  percentage=0.0; // will set percentage to zero
            }

         c.setHsv( (int)((1.0-percentage)*255), 255,255 );
         pen.setColor(c);
         brush.setColor(c);
         painterPtr->setPen(pen);
         painterPtr->setBrush(brush);
         if(scaleArrows){
            if(fixedArrowColorFlag){
               pen.setColor(univGraphSetPtr->arrowPen.color());
               brush.setColor(univGraphSetPtr->arrowPen.color());
               painterPtr->setPen(pen);
               painterPtr->setBrush(brush);
            }

            drawArrow((int)xCM,(int)zCM,vX,vZ,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr,arrowLength*percentage);
         }else{
            drawArrow((int)xCM,(int)zCM,vX,vZ,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr);
         }
         continue;
      }

      if(projData.projection=="yz"){
         magnitude2D=sqrt(vY*vY+vZ*vZ);
         percentage=percentageQuantity(magnitude2D,minMagnitude,maxMagnitude);
            if(percentage<0.0)
               percentage=0.0;
            if(percentage>1.0)
               percentage=1.0;
            if(percentage!=percentage){//perentage is nan - this happens e.g. when min and max concentrations are the same
                  percentage=0.0; // will set percentage to zero
            }

         c.setHsv( (int)((1.0-percentage)*255), 255,255 );
         pen.setColor(c);
         brush.setColor(c);
         painterPtr->setPen(pen);
         painterPtr->setBrush(brush);
         if(scaleArrows){
            if(fixedArrowColorFlag){
               pen.setColor(univGraphSetPtr->arrowPen.color());
               brush.setColor(univGraphSetPtr->arrowPen.color());
               painterPtr->setPen(pen);
               painterPtr->setBrush(brush);
            }
            drawArrow((int)yCM,(int)zCM,vY,vZ,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr,arrowLength*percentage);
         }else{
            drawArrow((int)yCM,(int)zCM,vY,vZ,univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,arrowLength,painterPtr);
         }
         continue;
      }

   }
   
   painterPtr->end();
   ///painting legend
   if(legendEnableVector && ! fixedArrowColorFlag){
      paintLegend(minMagnitude , maxMagnitude,"d","vector");
   }

}

void Graphics2DBase::paintCellVectorFieldLattice(){


   if(!currentVectorCellLevelFieldPtr){
      cerr<<"currentVectorCellLevelFieldPtr is null"<<endl;
      return;
   }



   //bool minInitialized=false;

   ///adding legend size
   
   if(legendEnableVector){
      labelSize=QSize(projData.sizeL ,projData.sizeM+legendWidth);
   }else{
      labelSize=QSize(projData.sizeL ,projData.sizeM);
   }
   labelSize*=(double)univGraphSetPtr->zoomFactor;


//    setFixedSize(labelSize);
//    pixmap()->resize(labelSize);
//    pixmap2D=QPixmap(labelSize);

   preDrawTask();
   
   cerr<<" \n\n\n\n overlayVectorCellField "<<overlayVectorCellFields<<endl;
   if(overlayVectorCellFields){
      paintLatticeCore();
      // paintCellVectorFieldLatticeCore(false);
      paintCellVectorFieldLatticeCore(false);
   }else{
      paintCellVectorFieldLatticeCore();
   }
   
   

   postDrawTask();


}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintLatticeCore(bool _erasePrevious){
      std::map<unsigned short,QPen> & typePenMap = univGraphSetPtr->typePenMap;
      std::map<unsigned short,QBrush> & typeBrushMap = univGraphSetPtr->typeBrushMap;
      


      std::map<unsigned short,QPen>::iterator pos;
      std::map<unsigned short,QBrush>::iterator posBrush;
      QPen * penPtr;
      QBrush *brushPtr;


      if(painterPtr->isActive() ){
         painterPtr->end(); ///ending active painter
      }
//       painterPtr->begin(pixmap());
      initPainter();


//       cerr<<"\n\n after begin painterPtr->isActive()="<<painterPtr->isActive()<<endl;
      if(_erasePrevious){
         pos=typePenMap.find(0);
         penPtr=&(pos->second);
         paintBackground(penPtr->color());
      }

//       cerr<<"after filling color"<<endl;
//       for(unsigned int x = 2/*projData.xMin*/ ; x < 3/*projData.xMax*/  ; ++x)
//          for(unsigned int y = 2/*projData.yMin*/ ; y < 3/*projData.yMax*/ ; ++y)
      for(unsigned int x = projData.xMin ; x < projData.xMax  ; ++x)
         for(unsigned int y = projData.yMin ; y < projData.yMax ; ++y)

            for(unsigned int z = projData.zMin ; z < projData.zMax ; ++z){

            if(graphFieldsPtr->field3DGraphicsData[x][y][z].type==0){
//                painterPtr->setPen(brushPtr->color());
               continue;
            }            

            pos=typePenMap.find(graphFieldsPtr->field3DGraphicsData[x][y][z].type);
            
            if(pos!=typePenMap.end()){
               penPtr=&(pos->second);
            }else{
               penPtr=&univGraphSetPtr->defaultPen;
            }

            posBrush=typeBrushMap.find(graphFieldsPtr->field3DGraphicsData[x][y][z].type);
            if(posBrush!=typeBrushMap.end()){
               brushPtr=&(posBrush->second);
               
            }else{
               
               brushPtr=&univGraphSetPtr->defaultBrush;
               
            }
                        
            
            ///painter->begin(imageLabel->pixmap());
            painterPtr->setPen(*penPtr);
            painterPtr->setPen(*&univGraphSetPtr->borderPen);///borderline
            painterPtr->setBrush(*brushPtr);///rectangle fill color

            


            if(projData.projection=="xy"){
               paintPixelXY(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               
               continue;
            }

            if(projData.projection=="xz"){
               paintPixelXZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               continue;
            }

            if(projData.projection=="yz"){
               paintPixelYZ(x, y,z, univGraphSetPtr->zoomFactor, univGraphSetPtr->zoomFactor,painterPtr);
               continue;
            }

                                                
      }
      painterPtr->end();

}

void Graphics2DBase::paintLattice(){



   
//       cerr<<"PAINT LATTICE "<<endl;
      labelSize=QSize(projData.sizeL ,projData.sizeM);
//       cerr<<"PAINT LATTICE 1"<<endl;
// 		cerr<<"univGraphSetPtr="<<univGraphSetPtr<<endl;
      labelSize*=(double)univGraphSetPtr->zoomFactor;
// 		cerr<<"PAINT LATTICE 3"<<endl;
      preDrawTask();
// 		cerr<<"PAINT LATTICE 3"<<endl;
      paintLatticeCore();
// 		cerr<<"PAINT LATTICE 5"<<endl;
      postDrawTask();
// 		cerr<<"PAINT LATTICE 5"<<endl;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::drawArrow(int x, int y ,float vX, float vY , int scaleM, int scaleN,int arrowLength ,  QPainter *painter, double _lengthScale){

   painter->save();
   if(arrowLength<1){
      painter->restore();
      return;
   }
   static double pi=acos(-1.0);
//    static QPointArray a(3);
   static QPolygon a(3);
   a[0] = QPoint((arrowLength)*scaleM , 0 );
   a[1] = QPoint((arrowLength-1)*scaleM , scaleN*(+1) );
   a[2] = QPoint((arrowLength-1)*scaleM , scaleN*(-1) );
   
   
   double angle;
   
   double length=sqrt(1.0*vX*vX+vY*vY);
   
   if(length==0.0){
      painter->restore();
      return;
   }
   angle=acos(vX/length);
   if(vY<0){
      angle=2*pi-angle;
   }
   //rad to deg conversion  
   angle*=180/pi;
   //inverse order of transfoirmation - listed first is done last -  here, we first rotate about (0,0,z), then translate
   painter->translate( x*scaleM , y*scaleN );
   painter->rotate(angle);

//    painter->drawPolygon(a);

   painter->scale(_lengthScale,_lengthScale);
   //painter->drawLine( x*scaleM , y*scaleN , (x+arrowLength-1)*scaleM , y*scaleN);
   painter->drawLine( 0 , 0 , (arrowLength-1)*scaleM , 0);
//    painter->scale(1.0/_lengthScale,1.0/_lengthScale);
   painter->drawPolygon(a);
   
   
   //cerr<<" angle="<<angle<<" x="<<x<<" y="<<y<<" vX="<<vX<<" vY="<<vY<<"arrowLength="<<arrowLength<<endl;
   
   
   painter->restore();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Coordinates3D<double> Graphics2DBase::HexCoordXY(unsigned int x,unsigned int y,unsigned int z){

   if(z%2){//odd z
      if(y%2)//odd
         return Coordinates3D<double>(x , sqrt(3.0)/2.0*(y+2.0/3.0), z*sqrt(6.0)/3.0 );
      else//#even
         return Coordinates3D<double>( x+0.5 ,  sqrt(3.0)/2.0*(y+2.0/3.0) , z*sqrt(6.0)/3.0);
   }
   else{
      if(y%2)//#odd
         return Coordinates3D<double>(x , sqrt(3.0)/2.0*y, z*sqrt(6.0)/3.0 );
      else//even
         return Coordinates3D<double>( x+0.5 ,  sqrt(3.0)/2.0*y , z*sqrt(6.0)/3.0);
   }
}

void Graphics2DBase::drawHexagonXY(int x, int y, int scaleM,  QPainter *painter){

   painter->save();
//    static QPolygonF hexagon(6);
//    static double sqrt_3_3_scaleM=sqrt(3.0)/3.0*scaleM;
//    hexagon[0] = QPointF(0. , sqrt_3_3_scaleM );
//    hexagon[1] = QPointF(0.5*scaleM , 0.5*sqrt_3_3_scaleM);
//    hexagon[2] = QPointF(0.5*scaleM, -0.5*sqrt_3_3_scaleM);
//    hexagon[3] = QPointF(0. , -sqrt_3_3_scaleM);
//    hexagon[4] = QPointF(-0.5*scaleM , -0.5*sqrt_3_3_scaleM);
//    hexagon[5] = QPointF(-0.5*scaleM , 0.5*sqrt_3_3_scaleM);

   
   

   Coordinates3D<double> transCoords=HexCoordXY(x,y,0);
   painter->setPen(painter->background().color());///borderline
   painter->setPen(painter->brush().color());///borderline
   painter->translate( 1.0*transCoords.x*scaleM , 1.0*transCoords.y*scaleM );
   painter->scale(scaleM,scaleM);
   painter->drawPolygon(hexagon);

   painter->restore();




}

void Graphics2DBase::drawRectangleXY(int x, int y, int scaleM,  QPainter *painter){

   painter->save();
   
   
//    static QPointArray a(3);
   static QPolygonF a(4);
   double lengthScale=1.0;

   a[0] = QPointF(0.5,0.5);
   a[1] = QPointF(0.5,-0.5);
   a[2] = QPointF(-0.5,-0.5);
   a[3] = QPointF(-0.5,0.5);


   for (int i =0 ; i< 4 ; ++i)
      a[i]*=lengthScale*scaleM;

   Coordinates3D<double> transCoords;
   transCoords.x=x;
   transCoords.y=y;
   transCoords.z=0;

   painter->translate( transCoords.x*scaleM , transCoords.y*scaleM );
   painter->drawPolygon(a);

   painter->restore();




}



void Graphics2DBase::paintHexPixelXY(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){
   drawHexagonXY(l, m, scaleM,painter);
}


void Graphics2DBase::paintPixelXY(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){

   if(latticeType==CompuCell3D::HEXAGONAL_LATTICE){
      paintHexPixelXY(l, m, n, scaleM,scaleN,painter);
   }else{
      painter->fillRect(l*scaleM,m*scaleN,scaleM,scaleN,painter->brush());
   }
   

   
   

    if(univGraphSetPtr->bordersOn){
        ///paintBorders(m,n,scaleM,scaleN,painter);
      paintBordersXY(l,m,n,scaleM,scaleN,painter);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintPixelXZ(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){
   painter->fillRect(l*scaleM,n*scaleN,scaleM,scaleN,painter->brush());

    if(univGraphSetPtr->bordersOn){
        ///paintBorders(m,n,scaleM,scaleN,painter);
      paintBordersXZ(l,m,n,scaleM,scaleN,painter);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintPixelYZ(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){
   painter->fillRect(m*scaleM,n*scaleN,scaleM,scaleN,painter->brush());

    if(univGraphSetPtr->bordersOn){
        ///paintBorders(m,n,scaleM,scaleN,painter);
      paintBordersYZ(l,m,n,scaleM,scaleN,painter);
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintHexBordersXY(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){

   painter->save();
   
   Coordinates3D<double> transCoords=HexCoordXY(l,m,0);
   painter->translate( 1.0*transCoords.x*scaleM , 1.0*transCoords.y*scaleM );
   painter->scale(scaleM,scaleM);
//    painter->setPen(QColor("white"));
   if(m%2){//y_odd
    
      if(l-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[l-1][m][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[4]);
            }
      }

      if(l-1>=0 && m+1 < graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[l-1][m+1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[5]);
            }
      }

      if(m+1 < graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[l][m+1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[0]);
            }
      }

      if(l+1 < graphFieldsPtr->getSizeL()){
            if(graphFieldsPtr->field3DGraphicsData[l+1][m][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[1]);
            }
      }


      if(m-1 >=0){
            if(graphFieldsPtr->field3DGraphicsData[l][m-1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[2]);
            }
      }

      if(l-1>=0 && m-1 >=0){
            if(graphFieldsPtr->field3DGraphicsData[l-1][m-1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[3]);
            }
      }

   }else{//y_even
      
      if(l-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[l-1][m][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[4]);
            }
      }

      if(m+1 < graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[l][m+1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[5]);
            }
      }

      if(l+1< graphFieldsPtr->getSizeL() && m+1 < graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[l+1][m+1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[0]);
            }
      }


      if(l+1 < graphFieldsPtr->getSizeL()){
            if(graphFieldsPtr->field3DGraphicsData[l+1][m][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[1]);
            }
      }

      if(l+1< graphFieldsPtr->getSizeL() && m-1 >=0){
            if(graphFieldsPtr->field3DGraphicsData[l+1][m-1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[2]);
            }
      }

      if(m-1 >=0){
            if(graphFieldsPtr->field3DGraphicsData[l][m-1][n].id != graphFieldsPtr->field3DGraphicsData[l][m][n].id){
               painter->drawLine(bordersHex[3]);
            }
      }

   }
   painter->restore();
}

void Graphics2DBase::paintBordersXY(int l,int m, int n, int scaleM, int scaleN, QPainter *painter){
   if(latticeType==CompuCell3D::HEXAGONAL_LATTICE){
      paintHexBordersXY(l,m,n,scaleM,scaleN,painter);
   }else{
    
         if( leftBorderXY(l, m, n) ){
            painter->drawLine(scaleM*l,scaleN*m,scaleM*l,scaleN*m+scaleN);
      
         }
      
         if( rightBorderXY(l,m, n) ){
            painter->drawLine(scaleM*(l+1)-1, scaleN*m, scaleM*(l+1)-1, scaleN*(m+1));
         }
      
      
            if( bottomBorderXY(l,m, n) ){
               painter->drawLine(scaleM*l, scaleN*m, scaleM*(l+1), scaleN*m);
            }
      
      
      
            if( upperBorderXY(l,m, n) ){
               painter->drawLine(scaleM*l, scaleN*(m+1)-1, scaleM*(l+1), scaleN*(m+1)-1);
            }
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::rightBorderXY(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_L+1<graphFieldsPtr->getSizeL()){
            if(graphFieldsPtr->field3DGraphicsData[_L+1][_M][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::leftBorderXY(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_L-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L-1][_M][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::upperBorderXY(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_M+1<graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M+1][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::bottomBorderXY(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_M-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M-1][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintBordersXZ(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){

    if( leftBorderXZ(l, m, n) ){
      painter->drawLine(scaleM*l,scaleN*n,scaleM*l,scaleN*n+scaleN);

    }

   if( rightBorderXZ(l,m, n) ){
      painter->drawLine(scaleM*(l+1)-1, scaleN*n, scaleM*(l+1)-1, scaleN*(n+1));
   }


      if( bottomBorderXZ(l,m, n) ){
         painter->drawLine(scaleM*l, scaleN*n, scaleM*(l+1), scaleN*n);
      }



      if( upperBorderXZ(l,m, n) ){
         painter->drawLine(scaleM*l, scaleN*(n+1)-1, scaleM*(l+1), scaleN*(n+1)-1);
      }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::rightBorderXZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_L+1<graphFieldsPtr->getSizeL()){
            if(graphFieldsPtr->field3DGraphicsData[_L+1][_M][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::leftBorderXZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_L-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L-1][_M][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::upperBorderXZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_N+1<graphFieldsPtr->getSizeN()){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N+1].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::bottomBorderXZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_N-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N-1].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Graphics2DBase::paintBordersYZ(int l,int m, int n,int scaleM, int scaleN,QPainter *painter){

    if( leftBorderYZ(l, m, n) ){
      painter->drawLine(scaleM*m,scaleN*n,scaleM*m,scaleN*n+scaleN);

    }

   if( rightBorderYZ(l,m, n) ){
      painter->drawLine(scaleM*(m+1)-1, scaleN*n, scaleM*(m+1)-1, scaleN*(n+1));
   }


      if( bottomBorderYZ(l,m, n) ){
         painter->drawLine(scaleM*m, scaleN*n, scaleM*(m+1), scaleN*n);
      }



      if( upperBorderYZ(l,m, n) ){
         painter->drawLine(scaleM*m, scaleN*(n+1)-1, scaleM*(m+1), scaleN*(n+1)-1);
      }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::rightBorderYZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_M+1<graphFieldsPtr->getSizeM()){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M+1][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::leftBorderYZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_M-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M-1][_N].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::upperBorderYZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_N+1<graphFieldsPtr->getSizeN()){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N+1].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Graphics2DBase::bottomBorderYZ(  int _L,int _M, int _N){

         if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N].type==0)
            return false;
            
         if(_N-1>=0){
            if(graphFieldsPtr->field3DGraphicsData[_L][_M][_N-1].id != graphFieldsPtr->field3DGraphicsData[_L][_M][_N].id){
               return true;
            }else{
               return false;
            }
         }else{
            return true;
         }
         
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Graphics2DBase::doContourLines(){
   numberOfContours=10;
   static int nc;   
   static floatField2D_t field2D;
   static int ilb=0;
   static int iub;
   static int jlb=0;
   static int jub;
   static string projection;
   
   static vector<float> iVec;
   static vector<float> jVec;
   static vector<float> levelVec;

   static unsigned int x,y,z;
   static unsigned int *iPtr=0,*jPtr=0; //they are initialized here only during  first call to this function
   floatField3D_t & concentrationField = *currentConcentrationFieldPtr;
   
   double scaleA=1.0,scaleB=1.0;

   if(projData.projection=="xy"){
      cerr<<" latticeType="<<latticeType<<endl;
      if(latticeType==CompuCell3D::HEXAGONAL_LATTICE){
         scaleB=sqrt(3.0)/2.0;
      }
   }

   if(projection!=projData.projection){//we have changed projection we need to do some reallocations
      iPtr=0;
      jPtr=0;
      projection=projData.projection;
      
      if(projection=="xy"){
         iub=projData.xMax-projData.xMin;
         jub=projData.yMax-projData.yMin;
         iPtr=&x;
         jPtr=&y;


      }
      else if (projection=="xz"){
         iub=projData.xMax-projData.xMin;
         jub=projData.zMax-projData.zMin;
         iPtr=&x;
         jPtr=&z;
         
      }

      else if (projection=="yz"){
         iub=projData.yMax-projData.yMin;
         jub=projData.zMax-projData.zMin;
         iPtr=&y;
         jPtr=&z;
         
      }
  
      field2D.assign(iub,vector<float>(jub));
      iVec.assign(iub,0);
      jVec.assign(jub,0);

      for(int i = 0 ; i < iVec.size() ; ++i ){
         iVec[i]=i;
      }

      for(int j = 0 ; j < jVec.size() ; ++j ){
         jVec[j]=j;
      }
            
   }

   
   if(nc!=numberOfContours){
      nc=numberOfContours;
      levelVec.assign(nc,0.0);
   }

   if( !iPtr || !jPtr ){
      cerr<<"Uninitialized projection related pointers. Exiting..."<<endl;
      exit(0);
      
   }  
   
   //initialize contour threshold
   float step = (maxConcentration-minConcentration)/nc;
   for(unsigned int i = 0 ; i < levelVec.size() ; ++i ){

      levelVec[i]=minConcentration+i*step;
   }

   
   for( x = projData.xMin ; x < projData.xMax  ; ++x)
      for( y = projData.yMin ; y < projData.yMax ; ++y)
         for( z = projData.zMin ; z < projData.zMax ; ++z){
         
            field2D[*iPtr][*jPtr]=concentrationField[x][y][z];
         }

   
     
   
//    cerr<<"iVec.size()="<<iVec.size()<<" jVec.size()="<<jVec.size()<<endl;


   painterPtr->setPen(*&univGraphSetPtr->contourPen);
   cerr<<"scaleA="<<scaleA<<" scaleB="<<scaleB<<endl;
   conrec(field2D,ilb,iub-1,jlb,jub-1,&iVec[0],&jVec[0],nc,&levelVec[0],painterPtr,univGraphSetPtr->zoomFactor,scaleA,scaleB);
   
   
}



