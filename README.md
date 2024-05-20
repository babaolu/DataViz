#Data Vizualization project
The aim of this project is to create a website where anyone can view their data graphically, and compare how your different variables relate to each other

Running Docker Image
====================
For ease of use, this web application can be run in a docker container with the help of the docker files. The main _Dockerfile_ incorporates the complete build while the other two are used to separate the app into its front and back end, and can therefore be run separately.
=> Make sure to set the NEXT_PUBLIC_DATAVIZ_URL ENV variable in the Dockerfile before building your image
