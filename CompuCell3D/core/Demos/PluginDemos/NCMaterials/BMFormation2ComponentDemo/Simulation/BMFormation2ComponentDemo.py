from cc3d import CompuCellSetup

from BMFormation2ComponentDemoSteppables import BMFormation2ComponentDemoSteppable
CompuCellSetup.register_steppable(steppable=BMFormation2ComponentDemoSteppable(frequency=1))

CompuCellSetup.run()