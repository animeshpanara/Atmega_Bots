i=imread('don.jpg');
imshow(i)
j=rgb2gray(i);
figure,imshow(j)
level=graythresh(j);
k=im2bw(j,level);
figure,imshow(k)