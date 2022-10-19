#!/bin/sh
./compile.sh
echo "Without OffShell:"
./QED_AllParticles_IO.x --particles "in_electron,in_electron,out_photon,out_electron,out_electron"
echo "------------------"
echo ""
echo "With OffShell:"
./QED_AllParticles_IO.x --particles "OffShell_in_electron,in_electron,out_photon,out_electron,out_electron"
./QED_AllParticles_IO.x --particles "OffShell_in_electron,in_electron,OffShell_out_photon,out_electron,out_electron"
