close
clear
imaqreset

vid=videoinput('winvideo',1,'YUY2_640x480'); % All arguments may be different for different PC
set(vid,'ReturnedColorSpace','rgb');
triggerconfig(vid, 'manual');
  start(vid);
      tic
i=getsnapshot(vid);
ihsv=rgb2hsv(i);
toc
imtool(ihsv);
stop(vid);

