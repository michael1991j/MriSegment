import os
import shutil

# Build list of CMakeLists.txt locations within the src folder
files = []
with open('List.txt', 'rU') as f:
	for line in f:
		files.append(line.rstrip('\n'))

# Set top directory (MriSegment)
top = os.getcwd()

# Check if Build folder exists, and if it does, remove it
#if os.path.exists(top + '/Build'):
#	shutil.rmtree('Build')

# Make new Build Folder
#os.mkdir('Build')
os.chdir('Build')

# Populate Build folder with cmake files
for file in files:
	os.system('mkdir -p ' + file)
	os.chdir(file)
	os.system('cmake ' + top + '/src/' + file)
	os.system('make')
	os.system('make install')
	os.chdir(top + '/Build')

