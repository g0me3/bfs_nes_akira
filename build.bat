@echo off

:again

echo assembling...

cd nas
for %%f in (*.nas) do call :dodasm %%f > NUL

dasm hdr.nas -f3 -o!akira.hdr > NUL
dasm chr.nas -f3 -o!akira.chr > NUL
goto :cleanup

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

:cleanup
echo build...
copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin tmp0.bin > NUL
copy /b bank8.bin+bank9.bin+bankA.bin+bankB.bin+bankC.bin+bankD.bin+bankEF.bin tmp1.bin > NUL
copy /b tmp0.bin+tmp1.bin !akira.prg > NUL
nesimage j !akira > NUL

echo cleanup...
for %%f in (*.bin) do del %%f
del !akira.prg
del !akira.hdr
del !akira.chr

copy /b !akira.nes ..\!akira.nes > NUL

cd ..

echo done.
