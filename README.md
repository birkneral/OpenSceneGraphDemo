# OpenSceneGraphDemo

This repository was created as part of the presentation with the topic "OpenSceneGraph" within the course "Programming of Graphics Shaders" in the WS2020/2021 of the technical college Nuremberg. It contains one solution file with the two projects HelloOpenSceneGraph and OpenSceneGraphPlayground. Further, it contains the binaries, header files and the data of [OpenSceneGraph](http://www.openscenegraph.org/) Version 3.6.5 created by [Objexx Engineering](https://objexx.com/OpenSceneGraph.html), as well as, the binaries and header files for [GLEW](http://glew.sourceforge.net/) (to use them for integrating [Dear ImGui](https://github.com/ocornut/imgui) in the OpenSceneGraphPlayground project), within the [Dependencies folder](/Dependencies).

## Setup
The solution and the project are set up to be used with Visual Studio 2019 on Windows 10. For the compilation of the OpenSceneGraphPlayground project, a compiler that supports at least the C++ 17 language standard needs to be available, since some features of C++ 17 are used during file operations within this project. Both projects should be compilable and executable within Visual Studio with Debug and Release settings. If any errors occur, please don´t hesitate to send an e-mail to birkneral69148@th-nuernberg.de.

## HelloOpenSceneGraph Project
This project is set up with all needed OpenSceneGraph dependencies. It shows a minimal application that uses OpenSceneGraph for rendering. It is mainly inspired by the sample described in chapter 1 part "Time for action - say "Hello World" OSG style" of the book [OpenSceneGraph 3.0: Beginner´s Guide](http://www.openscenegraph.org/index.php/documentation/books/10-openscenegraph-beginners-guide-published). This book is also available as an e-book in the library of the technical college Nuremberg.

The project is intended to show the basic use of OpenSceneGraph. It also can be used as a basis for own projects, since the dependencies for OpenSceneGraph are already set up. The view of the application during execution can be adjusted by using pan operations. Besides, it is possible to move the camera in or out by holding the right mouse button and moving the cursor up or down (or by using the mouse wheel). Multiple button presses on "S" display statistics provided by OpenSceneGraph.

## OpenSceneGraphPlayground Project
The OpenSceneGraphPlayground offers an interactive GUI to edit a scene graph that is created by utilizing the OpenSceneGraph toolkit. The GUI is rendered with the use of Dear ImGui. This project intends to show how different nodes and settings affect the rendering of the scene graph. The implementation should also show how the manipulation of a scene graph can be implemented and how the settings of individual nodes can be adjusted by using the so-called StateSets of nodes.

The control of the application is mainly carried out via Dear ImGui. Most of the elements of Dear ImGui can be operated by using mouse clicks. For some fields, it is necessary to make keyboard inputs (e.g. to define positions). Like in the HelloOpenSceneGraph application, the mouse wheel and panning operations can be used to adjust the view on the scene and multiple button presses on "S" also display statistics provided by OpenSceneGraph, since these features are available per default when using the OpenSceneGraph viewer.

To carry out operations on the scene graph, a node in the tree view of the Dear ImGui window must be selected by mouse click (see number 1 on screenshot below). After the selection, all options that are possible for this type of node will be displayed in the ImGui window (see number 2 on screenshot below). If an option is opened, different GUI elements, depending on the operation, appear and the desired operation can be carried out by a button click.

![Screenshot of the Editor](/Documentation/Screenshots/SelectionAndOptions.png)

## Not self-written Classes and Headers
To be able to use Dear ImGui, all files within the [imgui folder in the include directory](/OpenSceneGraphPlayground/include/imgui), as well as all files within the [imgui folder in the src directory](/OpenSceneGraphPlayground/src/imgui) were copied from the [Dear ImGui repository](https://github.com/ocornut/imgui). 

For the integration of Dear ImGui within OpenSceneGraph, the [OsgImGuiHandler class](/OpenSceneGraphPlayground/src/OsgImGuiHandler.cpp) and the [OsgImGuiHandler](/OpenSceneGraphPlayground/include/OsgImGuiHandler.cpp) header from [Tordans imgui-osg repository](https://github.com/Tordan/imgui-osg) were used.
