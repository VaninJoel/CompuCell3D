from cc3d import CompuCellSetup

from BMFormation3ComponentDemoSteppables import BMFormation3ComponentDemoSteppable
CompuCellSetup.register_steppable(steppable=BMFormation3ComponentDemoSteppable(frequency=1))

CompuCellSetup.run()