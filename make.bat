@echo off

start "" "..\..\..\tools\TextPad 7\TextPad.exe" ram.inc macroses.inc bankEF.inc draw_engine.inc intro.inc scene0.inc scene1.inc scene2.inc scene3.inc scene4.inc scene5.inc scene6.inc scene7.inc scene8.inc scene9.inc sceneA.inc sceneB.inc sceneC.inc sceneD.inc sceneE.inc sceneF.inc scene10.inc scene11.inc scene12.inc scene13.inc scene14.inc scene15.inc scene16.inc scene17.inc scene18.inc

pause 0

:again

cd nas

del !err.log
del !akira.nes
del !akira.chr
del !akira.hdr

echo assembling...

dasm bank0.nas -f3 -obank0.bin
dasm bank0.nas -f3 -l!akira.lst -obank0.bin >> !err.log

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

copy /b !akira.nes ..\!akira.nes
cd ..

echo done.
pause 0

goto :again

:eof
