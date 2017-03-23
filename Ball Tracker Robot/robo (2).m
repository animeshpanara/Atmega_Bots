imaqreset % To unload all previous adapters
clear all % To clear all previous variable
close % To close all previous windows


parport=digitalio('parallel','LPT1');
hwline=addline(parport,0:7,'out');

bvdatar=[1 0 1 0 0 0 0 0];% Parallel port data for right turn
bvdataf=[0 1 1 0 0 0 0 0]; % Parallel port data for forward motion
bvdatal=[0 1 0 1 0 0 0 0]; % Parallel port data for left turn
bvdatas=[1 1 1 1 0 0 0 0]; % Parallel port data for stop
bvdatab=[1 0 0 1 0 0 0 0]; % Parallel port data for move back


image1_h_mean=.07; % Hue component of Ball's color
image1_s_mean=.7; % Saturation component of Ball's color
image1_v_mean=.6; % Value component of Ball's color


vid=videoinput('winvideo',1,'YUY2_640x480'); % Arguments May change
set(vid,'ReturnedColorSpace','rgb'); %Arguments May Change
triggerconfig(vid, 'manual');
preview(vid);
 start(vid);
while 1>0

   

image2rgb=getsnapshot(vid);
image2=rgb2hsv(image2rgb);

image2_h=image2(:,:,1);
image2_s=image2(:,:,2);
image2_v=image2(:,:,3);

[r c d]=size(image2rgb);
range=0.1;

for x=1:r
    for y=1:c
        if (((image2_h(x,y)<=(image1_h_mean+range))&&(image2_h(x,y)>=(image1_h_mean-range)))&&((image2_s(x,y)<=(image1_s_mean+range))&&(image2_s(x,y)>=(image1_s_mean-range)))&&((image2_v(x,y)<=(image1_v_mean+range))&&(image2_v(x,y)>=(image1_v_mean-range))))
            image3(x,y)=255;
        else
            image3(x,y)=0;
        end
    end
end

imshow(image3);
[label,numobjects]=bwlabel(image3,8);
graindata=regionprops(label,'basic');
x=find([graindata.Area]== max([graindata.Area])); % for more than one object in arena
if ((numobjects > 0) && (graindata(x(1)).Area >= 500))


s2='object with Area more than 500 found....moving straight';
disp(s2);
c=graindata(x(1)).Centroid; % Here 1 = x for more than one object

disp(sprintf('Centroid of the largest object is = %5.2f, %5.2f', c(1), c(2)))

disp(sprintf('Area of the largest object is = %10.2f', graindata(x(1)).Area));
disp(sprintf('Total number of objects found = %5d', numobjects));
putvalue(parport,bvdataf)
pause(.1);
putvalue(parport,bvdatas)
pause(.1);


else
s='no orange color object in the current view.....searching objects';
disp(s);
putvalue(parport,bvdatar)
pause(.1);
putvalue(parport,bvdatas)
pause(.1);
end
end


  