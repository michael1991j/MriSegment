# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3

# Include any dependencies generated for this target.
include CMakeFiles/helloworld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloworld.dir/flags.make

CMakeFiles/helloworld.dir/main.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/main.cpp.o: /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/helloworld.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/main.cpp.o -c /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3/main.cpp

CMakeFiles/helloworld.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3/main.cpp > CMakeFiles/helloworld.dir/main.cpp.i

CMakeFiles/helloworld.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3/main.cpp -o CMakeFiles/helloworld.dir/main.cpp.s

CMakeFiles/helloworld.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/helloworld.dir/main.cpp.o.requires

CMakeFiles/helloworld.dir/main.cpp.o.provides: CMakeFiles/helloworld.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/helloworld.dir/build.make CMakeFiles/helloworld.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/helloworld.dir/main.cpp.o.provides

CMakeFiles/helloworld.dir/main.cpp.o.provides.build: CMakeFiles/helloworld.dir/main.cpp.o

# Object files for target helloworld
helloworld_OBJECTS = \
"CMakeFiles/helloworld.dir/main.cpp.o"

# External object files for target helloworld
helloworld_EXTERNAL_OBJECTS =

helloworld: CMakeFiles/helloworld.dir/main.cpp.o
helloworld: CMakeFiles/helloworld.dir/build.make
helloworld: /usr/local/lib/libgdcmcharls.so
helloworld: /usr/local/lib/libgdcmjpeg16.so
helloworld: /usr/local/lib/libgdcmCommon.so
helloworld: /usr/local/lib/libgdcmjpeg8.so
helloworld: /usr/local/lib/libgdcmDICT.so
helloworld: /usr/local/lib/libgdcmMEXD.so
helloworld: /usr/local/lib/libgdcmDSED.so
helloworld: /usr/local/lib/libgdcmMSFF.so
helloworld: /usr/local/lib/libgdcmexpat.so
helloworld: /usr/local/lib/libgdcmopenjpeg.so
helloworld: /usr/local/lib/libgdcmIOD.so
helloworld: /usr/local/lib/libgdcmuuid.so
helloworld: /usr/local/lib/libgdcmjpeg12.so
helloworld: /usr/local/lib/libgdcmzlib.so
helloworld: /usr/lib/x86_64-linux-gnu/libQtGui.so
helloworld: /usr/lib/x86_64-linux-gnu/libQtCore.so
helloworld: /usr/local/lib/libDisplayImage.so
helloworld: /usr/local/lib/libMRIOpenCV.so
helloworld: /usr/local/lib/libopencv_videostab.so.2.4.8
helloworld: /usr/local/lib/libopencv_video.so.2.4.8
helloworld: /usr/local/lib/libopencv_ts.a
helloworld: /usr/local/lib/libopencv_superres.so.2.4.8
helloworld: /usr/local/lib/libopencv_stitching.so.2.4.8
helloworld: /usr/local/lib/libopencv_photo.so.2.4.8
helloworld: /usr/local/lib/libopencv_ocl.so.2.4.8
helloworld: /usr/local/lib/libopencv_objdetect.so.2.4.8
helloworld: /usr/local/lib/libopencv_nonfree.so.2.4.8
helloworld: /usr/local/lib/libopencv_ml.so.2.4.8
helloworld: /usr/local/lib/libopencv_legacy.so.2.4.8
helloworld: /usr/local/lib/libopencv_imgproc.so.2.4.8
helloworld: /usr/local/lib/libopencv_highgui.so.2.4.8
helloworld: /usr/local/lib/libopencv_gpu.so.2.4.8
helloworld: /usr/local/lib/libopencv_flann.so.2.4.8
helloworld: /usr/local/lib/libopencv_features2d.so.2.4.8
helloworld: /usr/local/lib/libopencv_core.so.2.4.8
helloworld: /usr/local/lib/libopencv_contrib.so.2.4.8
helloworld: /usr/local/lib/libopencv_calib3d.so.2.4.8
helloworld: /usr/lib/libboost_system-mt.so
helloworld: /usr/lib/libboost_filesystem-mt.so
helloworld: /usr/lib/libboost_thread-mt.so
helloworld: /usr/lib/libboost_date_time-mt.so
helloworld: /usr/lib/libboost_iostreams-mt.so
helloworld: /usr/lib/libboost_serialization-mt.so
helloworld: /usr/lib/libpcl_common.so
helloworld: /usr/lib/libflann_cpp_s.a
helloworld: /usr/lib/libpcl_kdtree.so
helloworld: /usr/lib/libpcl_octree.so
helloworld: /usr/lib/libpcl_search.so
helloworld: /usr/lib/libpcl_sample_consensus.so
helloworld: /usr/lib/libpcl_filters.so
helloworld: /usr/lib/libpcl_features.so
helloworld: /usr/lib/libpcl_keypoints.so
helloworld: /usr/lib/libOpenNI.so
helloworld: /usr/lib/libvtkCommon.so.5.8.0
helloworld: /usr/lib/libvtkRendering.so.5.8.0
helloworld: /usr/lib/libvtkHybrid.so.5.8.0
helloworld: /usr/lib/libvtkCharts.so.5.8.0
helloworld: /usr/lib/libpcl_io.so
helloworld: /usr/lib/libpcl_segmentation.so
helloworld: /usr/lib/libqhull.so
helloworld: /usr/lib/libpcl_surface.so
helloworld: /usr/lib/libpcl_registration.so
helloworld: /usr/lib/libpcl_recognition.so
helloworld: /usr/lib/libpcl_visualization.so
helloworld: /usr/lib/libpcl_outofcore.so
helloworld: /usr/lib/libpcl_people.so
helloworld: /usr/lib/libpcl_tracking.so
helloworld: /usr/lib/libpcl_apps.so
helloworld: /usr/lib/libboost_system-mt.so
helloworld: /usr/lib/libboost_filesystem-mt.so
helloworld: /usr/lib/libboost_thread-mt.so
helloworld: /usr/lib/libboost_date_time-mt.so
helloworld: /usr/lib/libboost_iostreams-mt.so
helloworld: /usr/lib/libboost_serialization-mt.so
helloworld: /usr/lib/libqhull.so
helloworld: /usr/lib/libOpenNI.so
helloworld: /usr/lib/libflann_cpp_s.a
helloworld: /usr/lib/libvtkCommon.so.5.8.0
helloworld: /usr/lib/libvtkRendering.so.5.8.0
helloworld: /usr/lib/libvtkHybrid.so.5.8.0
helloworld: /usr/lib/libvtkCharts.so.5.8.0
helloworld: /usr/lib/libpcl_common.so
helloworld: /usr/lib/libpcl_kdtree.so
helloworld: /usr/lib/libpcl_octree.so
helloworld: /usr/lib/libpcl_search.so
helloworld: /usr/lib/libpcl_sample_consensus.so
helloworld: /usr/lib/libpcl_filters.so
helloworld: /usr/lib/libpcl_features.so
helloworld: /usr/lib/libpcl_keypoints.so
helloworld: /usr/lib/libpcl_io.so
helloworld: /usr/lib/libpcl_segmentation.so
helloworld: /usr/lib/libpcl_surface.so
helloworld: /usr/lib/libpcl_registration.so
helloworld: /usr/lib/libpcl_recognition.so
helloworld: /usr/lib/libpcl_visualization.so
helloworld: /usr/lib/libpcl_outofcore.so
helloworld: /usr/lib/libpcl_people.so
helloworld: /usr/lib/libpcl_tracking.so
helloworld: /usr/lib/libpcl_apps.so
helloworld: /usr/lib/x86_64-linux-gnu/libGLU.so
helloworld: /usr/local/lib/libopencv_nonfree.so.2.4.8
helloworld: /usr/local/lib/libopencv_ocl.so.2.4.8
helloworld: /usr/local/lib/libopencv_gpu.so.2.4.8
helloworld: /usr/local/lib/libopencv_photo.so.2.4.8
helloworld: /usr/local/lib/libopencv_objdetect.so.2.4.8
helloworld: /usr/local/lib/libopencv_legacy.so.2.4.8
helloworld: /usr/local/lib/libopencv_video.so.2.4.8
helloworld: /usr/local/lib/libopencv_ml.so.2.4.8
helloworld: /usr/local/lib/libopencv_calib3d.so.2.4.8
helloworld: /usr/local/lib/libopencv_features2d.so.2.4.8
helloworld: /usr/local/lib/libopencv_highgui.so.2.4.8
helloworld: /usr/local/lib/libopencv_imgproc.so.2.4.8
helloworld: /usr/local/lib/libopencv_flann.so.2.4.8
helloworld: /usr/local/lib/libopencv_core.so.2.4.8
helloworld: /usr/lib/libvtkViews.so.5.8.0
helloworld: /usr/lib/libvtkInfovis.so.5.8.0
helloworld: /usr/lib/libvtkWidgets.so.5.8.0
helloworld: /usr/lib/libvtkHybrid.so.5.8.0
helloworld: /usr/lib/libvtkParallel.so.5.8.0
helloworld: /usr/lib/libvtkVolumeRendering.so.5.8.0
helloworld: /usr/lib/libvtkRendering.so.5.8.0
helloworld: /usr/lib/libvtkGraphics.so.5.8.0
helloworld: /usr/lib/libvtkImaging.so.5.8.0
helloworld: /usr/lib/libvtkIO.so.5.8.0
helloworld: /usr/lib/libvtkFiltering.so.5.8.0
helloworld: /usr/lib/libvtkCommon.so.5.8.0
helloworld: /usr/lib/libvtksys.so.5.8.0
helloworld: /usr/lib/x86_64-linux-gnu/libGL.so
helloworld: /usr/lib/x86_64-linux-gnu/libSM.so
helloworld: /usr/lib/x86_64-linux-gnu/libICE.so
helloworld: /usr/lib/x86_64-linux-gnu/libX11.so
helloworld: /usr/lib/x86_64-linux-gnu/libXext.so
helloworld: CMakeFiles/helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable helloworld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloworld.dir/build: helloworld
.PHONY : CMakeFiles/helloworld.dir/build

CMakeFiles/helloworld.dir/requires: CMakeFiles/helloworld.dir/main.cpp.o.requires
.PHONY : CMakeFiles/helloworld.dir/requires

CMakeFiles/helloworld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloworld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloworld.dir/clean

CMakeFiles/helloworld.dir/depend:
	cd /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3 /home/mri/Build/MriSegment/src/Test/Implementation/MRICV/Test3 /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3 /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3 /home/mri/Build/MriSegment/Build/Test/Implementation/MRICV/Test3/CMakeFiles/helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloworld.dir/depend

