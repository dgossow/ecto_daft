ecto_daft
================================================================================

ecto_daft contains ecto bindings to use DAFT for feature detection
and description [1]_.

To use it, you also need to put the DAFT library into your workspace
(https://github.com/dgossow/daft). If you use rosinstall, just put
this into your .rosinstall file:

``- git: {local-name: daft, uri: 'https://github.com/dgossow/daft.git'}``
``- git: {local-name: ecto_daft, uri: 'https://github.com/dgossow/ecto_daft.git'}``


Dependencies
--------------------------------------------------------------------------------

 - cmake
 - boost
 - git
 - ecto (https://github.com/plasmodic/ecto)
 - opencv2.3 deb from packages.ros.org, or source install from 
   https://code.ros.org/svn/opencv/branches/2.3/opencv

Code Style
--------------------------------------------------------------------------------
If you are using eclipse, you may use the style file available here:
  
  https://github.com/plasmodic/ecto/raw/master/misc/ecto.style.xml


.. [1] David Gossow, David Weikersdorfer, and Michael Beetz, 
       "Distinctive Texture Features from Perspective-Invariant Keypoints," 
       in International Conference on Pattern Recognition (ICPR), 2012.