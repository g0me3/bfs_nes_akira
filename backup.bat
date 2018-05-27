mkdir .\backup\current
mkdir .\backup\current\nas
mkdir .\backup\current\chr
mkdir .\backup\current\tlm
mkdir .\backup\current\msg_en
mkdir .\backup\current\msg_jp

copy /b *.bat .\backup\current\*.bat
copy /b *.inc .\backup\current\*.inc
copy /b nas\*.exe .\backup\current\nas\*.exe
copy /b nas\*.nas .\backup\current\nas\*.nas
copy /b chr\*.chr .\backup\current\chr\*.chr
copy /b tlm\*.* .\backup\current\tlm\*.*
copy /b msg_en\*.inc .\backup\current\msg_en\*.inc
copy /b msg_jp\*.inc .\backup\current\msg_jp\*.inc
copy /b *.txt .\backup\current\*.txt
