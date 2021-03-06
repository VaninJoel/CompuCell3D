from cc3d import CompuCellSetup

from diffusion_steady_state_ext_potentialSteppables import diffusion_steady_state_ext_potentialSteppable

CompuCellSetup.register_steppable(steppable=diffusion_steady_state_ext_potentialSteppable(frequency=1))

CompuCellSetup.run()
