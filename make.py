import os
import shutil

# Build list of CMakeLists.txt locations within the src folder
files = []
with open('List.txt', 'rU') as f:
	for line in f:
		files.append(line.rstrip('\n'))

# Set top directory (MriSegment)
top = os.getcwd()

# Check if Build folder exists, and if it doesn't, add it and go to it
if not os.path.exists(top + '/Build'):
	os.mkdir('Build')
os.chdir('Build')

# Generate list for user to select files to make
print('Choose path to make')
print('0:	All files')
i = 0
for file in files:
	i += 1
	print(str(i	) + ':	' + file)
selection = input('Selection number: ')

# Run cmake on each file and store in Build folder
if selection == 0:
	for file in files:
		os.system('mkdir -p ' + file)
		os.chdir(file)
		os.system('cmake ' + top + '/src/' + file)
		os.system('make')
		os.system('make install')
		os.chdir(top + '/Build')

# Run cmake on selected file and store in Build folder
else:
	choice = int(selection-1)
	os.system('mkdir -p ' + files[choice])
	os.chdir(files[choice])
	os.system('cmake ' + top + '/src/' + files[choice])
	os.system('make')
	os.system('make install')
	os.chdir(top + '/Build')

	

