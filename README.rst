ecto_daft
========================================

ecto_daft contains ecto bindings to use DAFT for feature detection
and description:

``D. Gossow, D. Weikersdorfer, and M. Beetz, "Distinctive Texture Features from Perspective-Invariant Keypoints," in International Conference on Pattern Recognition (ICPR), 2012.``

To use it, you need to put the DAFT library into your workspace:
https://github.com/dgossow/daft.

Dependencies
----------------------------------------

 - cmake
 - boost
 - git
 - python
 - ecto https://github.com/plasmodic/ecto
 - opencv2.3 deb from packages.ros.org, or source install from https://code.ros.org/svn/opencv/branches/2.3/opencv
 - python numpy dev libraries

Code Style
-----------------------------------------------
If you are using eclipse, you may use the style file available here:
  
  https://github.com/plasmodic/ecto/raw/master/misc/ecto.style.xml
