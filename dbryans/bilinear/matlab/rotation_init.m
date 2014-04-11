clc;
clear all;
close all;

%in = zeros(128,128);
in_a=imread('man.tiff');
in=in_a(1:1024,1:1024,1);

[rows cols] = size(in);
[Nrows Ncols] = size(in);
blk=10;
fps=1/(rows*(cols+3*blk));
out = zeros(rows, cols);

%nearest neighbour
flip_h = 0;
flip_v = 0;
zoomFac = 00;
theta = (40*pi)/180;
center_x = rows/2 ;
center_y = cols/2 ;

col_delx= ((1-2*flip_h)*cos(theta)/(zoomFac+2))*2;
col_dely= ((1-2*flip_h)*sin(theta)/(zoomFac+2))*2;

row_delx=-((1-2*flip_v)*sin(theta)/(zoomFac+2))*2;
row_dely= ((1-2*flip_v)*cos(theta)/(zoomFac+2))*2;


xstart_init=((2*flip_h-1)*cos(theta)-(2*flip_v-1)*sin(theta))*rows/(zoomFac+2) + center_x;
ystart_init=((2*flip_h-1)*sin(theta)+(2*flip_v-1)*cos(theta))*rows/(zoomFac+2) + center_y;


newRows = rows*zoomFac;
newCols = cols*zoomFac;

out = zeros(rows, cols);

xstart = xstart_init;
ystart = ystart_init;

col_delx_ws=ceil(col_delx*2^20);
col_dely_ws=ceil(col_dely*2^20);
row_delx_ws=ceil(row_delx*2^20)*2;
row_dely_ws=ceil(row_dely*2^20)*2; % mul 2 for pal interlace

xstart_init_ws = ceil(xstart_init*2^20);
ystart_init_ws = ceil(ystart_init*2^20);

% for i = 1: rows
%     %startx,starty = 20bits
%     %cost,sint = 16bits
%     dx = xstart;
%     dy = ystart;
%     for j = 1: cols
%         dy_r = clip(dy, 0, rows-1);
%         dx_r = clip(dx, 0, cols-1);
%         dy_i = round(dy_r);
%         dx_i = round(dx_r);
%         Rx = dx_r - dx_i;
%         Ry = dy_r - dy_i;
%         Wxpyp = (Rx) * (Ry);
%         Wxyp  = (Ry) - Wxpyp;
%         Wxpy  = (Rx) - Wxpyp;
%         Wxy   = (1 - Rx) - Wxyp;
%         dy_j=dy_i;
%         dx_j=dx_i;
%         if(dy_i==0)
%             dy_j=1;
%         end
%         if(dx_i==0)
%             dx_j=1;
%         end
%         out(i,j) = in(dy_j,dx_j);
%         row_a(i,j)=dy_i; %row
%         col_a(i,j)=dx_i; %col
% %        addr((i-1)*64+j)=bitor(bitshift(dx_i,6),dy_i);
% %        out(i,j)= Wxy*in(dy_i,dx_i) + Wxyp*in(dy_i+1,dx_i) + ...
% %                     Wxpy*in(dy_i,dx_i+1) + Wxpyp*in(dy_i+1,dx_i+1);
%                  
%         % dx and dy 20 bits         
%         dx = dx + col_delx;
%         dy = dy + col_dely;         
%     end  
%     
%     xstart = xstart + row_delx;
%     ystart = ystart + row_dely;    
% end


% % bilinear
cosTh = cos(theta);
sinTh = sin(theta);
for i = 1: Nrows-1
    it = i - Nrows/2;
    itcos = it*cosTh;
    itsin = it*sinTh;
    for j = 1: Ncols-1  
        jt = j - Ncols/2;
        ir = itcos - jt*sinTh;
        jr = itsin + jt*cosTh;
        ir = clip( (ir + Nrows/2), 1, Nrows-1);
        jr = clip( (jr + Ncols/2), 1, Ncols-1);
        si = floor(ir);
        sj = floor(jr);
        %w1 = jr - sj;
        %w2 = ir - si;
%         out(i,j)= (1-w1)*( (1-w2)*in(si,sj) + w2*in(si+1,sj) ) + ...
%                     w1*( (1-w2)*in(si, sj+1) + w2*in(si+1, sj+1) );
%         out(i,j)= 0.25*in(si,sj) + 0.25*in(si+1,sj)  + ...
%                     0.25*in(si, sj+1) + 0.25*in(si+1, sj+1);
          out(i,j) = in(si, sj);
    end
end

% bilinear w zoom
% zoomFac = 2;
% theta = 90;
% cosTh = cos(theta)/zoomFac;
% sinTh = sin(theta)/zoomFac;
% newRows = Nrows*zoomFac;
% newCols = Ncols*zoomFac;
% out2 = zeros(newRows, newCols);
% for i = 1: newRows
%     it = i - newRows/2;
%     itcos = it*cosTh;
%     itsin = it*sinTh;
%     for j = 1: newCols        
%         jt = j - newCols/2;
%         ir = itcos - jt*sinTh;
%         jr = itsin + jt*cosTh;
%         ir = clip( (ir + newRows/(2*zoomFac)), 1, Nrows-1);
%         jr = clip( (jr + newCols/(2*zoomFac)), 1, Ncols-1);
%         si = floor(ir);
%         sj = floor(jr);
%         w1 = jr - sj;
%         w2 = ir - si;
%         out2(i,j)= (1-w1)*( (1-w2)*in(si,sj) + w2*in(si+1,sj) ) + ...
%                     w1*( (1-w2)*in(si, sj+1) + w2*in(si+1, sj+1) );
%     end
% end
figure;imshow(in);        
figure;imshow(out/255);
