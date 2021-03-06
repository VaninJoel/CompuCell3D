import cc3d.CompuCellSetup as CompuCellSetup
from .ExtraFieldsSteppables import ExtraFieldVisualizationSteppable
from .ExtraFieldsSteppables import IdFieldVisualizationSteppable
from .ExtraFieldsSteppables import VectorFieldVisualizationSteppable
from .ExtraFieldsSteppables import VectorFieldCellLevelVisualizationSteppable
from .ExtraFieldsSteppables import DiffusionFieldSteppable

CompuCellSetup.register_steppable(steppable=ExtraFieldVisualizationSteppable(frequency=1))
CompuCellSetup.register_steppable(steppable=IdFieldVisualizationSteppable(frequency=1))
CompuCellSetup.register_steppable(steppable=VectorFieldVisualizationSteppable(frequency=1))
CompuCellSetup.register_steppable(steppable=VectorFieldCellLevelVisualizationSteppable(frequency=1))
CompuCellSetup.register_steppable(steppable=DiffusionFieldSteppable(frequency=1))

CompuCellSetup.run()
