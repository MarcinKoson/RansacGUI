# Searching for similar objects using RANSAC 

This is GUI application for my implementation of RANSAC  
https://github.com/MarcinKoson/Ransac

It searches for similar objects on two pictures.

![example](/example.png)

## Installation

Download installer from
https://github.com/MarcinKoson/RansacGUI/releases

If you want to build it yourself you need Qt Creator (https://www.qt.io/)  
and you must register library.  
To register library  use Regasm.exe  
	`regasm ransacDLL.dll /tlb:ransacDLL.tlb`  
	`regasm ransacDLL.dll /regfile `   
Then run created .reg file

## Usage

As an input application use haraff sift files. 
You can get generate it for .png image using 
[www.robots.ox.ac.uk/~vgg/research/affine/det_eval_files/extract_features2.tar.gz]()

Generate haraff sift file (Linux)  
`./extract_features_32bit.ln -haraff -sift -i yourpicture.png`  
Images with high resolution may cause crashes.

If you have needed files load them into application, choose parameters and click start.

### Parameters
* Size  
	>Size of neighborhood of pair.
* Cohesion  
	>Specifies how many pairs must be in neighborhood of each point of pair to accept pair as consistent. Inconsistent pairs are discarded. Should be smaller than size of neighborhood.
* Iterations  
	>Number of repetitions of model calculation in RANSAC.
* Max error  
	>Maximum error of the pair to be determined as matching the model.

## Technologies
Qt 6.1.2  
.NET Framework 4  
C++


