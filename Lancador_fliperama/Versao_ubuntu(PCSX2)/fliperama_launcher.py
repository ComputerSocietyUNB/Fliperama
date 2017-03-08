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

#versao para windows feita por Satoru (lancamento inicial) visando o ePSXe
#modificacao para usar em ubuntu realizada por Pedro Aurelio (em 05/03/2017) visando o PCSX2

#colocar a localizacao da pasta onde se encontra o emulador PCSX2

os.system('PCSX2 "/home/paca/Downloads/DragonBall Z - Budokai Tenkaichi 3 (USA) (En,Ja).iso" --fullscreen')

while (comando != '9'):

	comando = raw_input()
	
	if comando == 'g':
		print('[.] DragonBall Z - Budokai Tenkaichi 3')
		# adicionar o caminho completo para o tekken		
		os.system('PCSX2 "/home/paca/Downloads/DragonBall Z - Budokai Tenkaichi 3 (USA) (En,Ja).iso" --fullscreen')

	elif comando == 't':
		print('[.] Lancando Tekken 5')
		# adicionar o caminho completo para o tekken
		#os.system('PCSX2 "/home/paca/Downloads/DragonBall Z - Budokai Tenkaichi 3 (USA) (En,Ja).iso" --fullscreen')

	elif comando == 'h':
		print('[.] Lancando o emulador')
		os.system('PCSX2')

	elif comando == '9':
		print('[*] Saindo...')
	
	else:
		print('[!] Comando invalido')
