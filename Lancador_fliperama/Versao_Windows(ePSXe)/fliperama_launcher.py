#Para iniciar o script junto a inicializacao do Windows:
#	-Aperte WindowsKey + R para abrir o Executar
#	-Digite shell:startup e em seguida clique em OK
#	-Crie um atalho para o fliperama_launcher.py
#	-Mova o atalho para a pasta aberta pelo executar
#
#Obs: caso os arquivos .py no seu computador nao estejam associados
#	  ao python.exe, crie um .bat no modelo do codigo a seguir:
#
# <local onde esta instalado o python> <local onde esta o fliperama_launcher.py> %*
#
#exemplo:	c:\python27\python.exe C:\Users\fulano\Desktop\fliperama_launcher.py %*
#
#	  em seguida faca os passos acima criando o atalho para o seu .bat a movendo-o para
#	  a pasta aberta pelo shell::startup	



#	O programa utiliza da biblioteca os do python para fazer as chamadas de sistema
#	Ao iniciar, o programa ja lanca um jogo, apos este ser fechado e possivel selecionar outros
#	jogos dependendo da entrada.
#	
#	As isos dos jogos devem ser colocadas na pasta 'isos'
import os

comando = 'init'

#colocar a localizacao da pasta onde se encontra o emulador ePSXe
dir_ePSXe = 'C:\Users\\vitor_000\Desktop\ePSXe'

os.chdir(dir_ePSXe)


os.system('ePSXe.exe -nogui -loadbin "isos\Tekken 3\Tekken 3.cue"')

while (comando != '9'):

	comando = raw_input()
	
	if comando == 'g':
		print('[.] Lancando Tekken')
		os.system('ePSXe.exe -nogui -loadbin "isos\Tekken 3\Tekken 3.cue"')

	elif comando == 't':
		print('[.] Lancando Marvel vs Capcom')
		os.system('ePSXe.exe -nogui -loadbin "isos\Marvel vs. Capcom - Clash of Super Heroes\Marvel vs. Capcom - Clash of Super Heroes.cue"')

	elif comando == 'h':
		print('[.] Lancando ePSXe')
		os.system('ePSXe.exe')

	elif comando == '9':
		print('[*] Saindo...')
	
	else:
		print('[!] Comando invalido')
