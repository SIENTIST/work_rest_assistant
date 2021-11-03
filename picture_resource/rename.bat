cls
@echo off
color 
:: note:    change the image format input,default value is 'color'
:: option:  color/yuv12/yuv21
set switch=color
::
:: don't change the following code!!!
set img_format=jpg
if %switch% EQU yuv12 (
    set img_format=yuv
) 
if %switch% EQU yuv21 (
    set img_format=yuv
)
setlocal EnableDelayedExpansion
for /F "tokens=*" %%f in ('dir *.jpg  /A:-D /B') do (
    ren "%%f" "p%%f"
    echo "rename  %%f --> p%%f"
)

set num=0
for /F "tokens=*" %%f in ('dir *.jpg  /A:-D /B') do (
    ren "%%f" "!num!.%img_format%"
    echo "rename  %%f --> !num!.%img_format%"
    set /A num = !num! + 1
)