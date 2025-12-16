@echo off
rem run_pub_test.cmd - compilar, executar Q01 com pub.in e comparar com pubout
rem Coloque este arquivo na mesma pasta que Q01.java, pub.in e pubout.txt/pub.out

setlocal enableextensions enabledelayedexpansion

:: Mudar para o diretório do script
cd /d "%~dp0"

:clean_classes
echo Limpando .class antigos (se existirem)...
del /q "*.class" >nul 2>&1
echo.

:compile
echo Compilando Q01.java...
javac Q04.java
if errorlevel 1 (
  echo ERRO: compilacao falhou. Verifique mensagens acima.
  pause
  exit /b 1
)
echo Compilacao OK.
echo.

:check_input
if not exist "pub.in" (
  echo ERRO: arquivo 'pub.in' nao encontrado em %cd%.
  pause
  exit /b 1
)

:run
echo Executando Q01 com pub.in e salvando em mypubout.txt ...
java -cp . Q04 < "pub.in" > "mypubout.txt"
if errorlevel 1 (
  echo Aviso: Execucao retornou codigo de erro. Verifique a saida em mypubout.txt
) else (
  echo Execucao concluida com sucesso.
)
echo.

:compare
echo Procurando arquivo de saida publica (pubout.txt ou pub.out)...
if exist "pubout.txt" (
  echo Encontrado pubout.txt - comparando com mypubout.txt ...
  echo (Se \">\" aparecer, sao as diferencas) 
  fc "pubout.txt" "mypubout.txt"
) else if exist "pub.out" (
  echo Encontrado pub.out - comparando com mypubout.txt ...
  fc "pub.out" "mypubout.txt"
) else (
  echo NENHUM arquivo pubout encontrado (pubout.txt ou pub.out) - apenas gerei mypubout.txt
)
echo.

:: Opcional: normalizar espaços finais e comparar via PowerShell (mais tolerante a trailing spaces)
if exist "pubout.txt" (
  echo (Opcional) Normalizando e comparando com PowerShell...
  powershell -NoProfile -Command "(Get-Content 'pubout.txt') | ForEach-Object { $_.TrimEnd() } | Set-Content 'pubout.norm.txt'"
  powershell -NoProfile -Command "(Get-Content 'mypubout.txt') | ForEach-Object { $_.TrimEnd() } | Set-Content 'mypubout.norm.txt'"
  powershell -NoProfile -Command "Compare-Object (Get-Content 'pubout.norm.txt') (Get-Content 'mypubout.norm.txt') | Out-String | Write-Host"
)

necho.
echo CONCLUIDO.
pause
endlocal
