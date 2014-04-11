Nx=2048;
Ny=2048;

f=randn(Nx, Ny)+sqrt(-1)*randn(Nx, Ny);
ff=fft2(f);

frs=reshape(f,Nx*Ny,1);
ffrs=reshape(ff,Nx*Ny,1);

finp=zeros(2*Nx*Ny,1);
fout=zeros(2*Nx*Ny,1);

finp(1:2:end)=real(frs);
finp(2:2:end)=imag(frs);

fout(1:2:end)=real(ffrs);
fout(2:2:end)=imag(ffrs);

fileName=sprintf('../vectors/inp/fft2d_%dx%d.bin',Nx,Ny);
fid=fopen(fileName,'wb');
fwrite(fid,finp,'float32');
fclose(fid);

fileName=sprintf('../vectors/refout/fft2d_%dx%d.bin',Nx,Ny);
fid=fopen(fileName,'wb');
fwrite(fid,fout,'float32');
fclose(fid);
