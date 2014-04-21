import os
files = []
with open('List.txt', 'rU') as f:
	for line in f:
		files.append(line.rstrip('\n'))
top = os.getcwd()
os.mkdir('Build')
os.chdir('Build')
for file in files:
	os.mkdir(file)
	os.chdir(file)
	os.system('cmake' + top + '/src/' + file)
	os.chdir('..')

