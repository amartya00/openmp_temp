close all
clear all

N = 1000;
D=6.5;
M = 3000;
sig=32;

% % 2D
x_or = [2*randn(1,N)+D, randn(1,N)-D, 3*randn(1,N)+D]; % single Gaussian
y_or = [2*randn(1,N)-D, randn(1,N)+D, 3*randn(1,N)+D]; % single Gaussian
z_or = [2*randn(1,N)+D, randn(1,N)+D, 3*randn(1,N)-D]; % single Gaussian
x=x_or;
y=y_or;
z=z_or;

figure, plot3(x_or,y_or,z_or,'b.');
hold on
dist(1:N)=0;

for k=1:7
for j=1:M
for i=1:M
    dist(j,i)=(x(j)-x_or(i))^2+(y(j)-y_or(i))^2+(z(j)-z_or(i))^2;
end
end

Gauss_kernel=exp(-dist/sig);
Sum_Gauss=sum(Gauss_kernel,2);

new_x(M)=0;
new_y(M)=0;
new_z(M)=0;

for i=1:M
    new_x(i)=x_or(1,:)*Gauss_kernel(i,:)'/Sum_Gauss(i);
    new_y(i)=y_or(1,:)*Gauss_kernel(i,:)'/Sum_Gauss(i);
    new_z(i)=z_or(1,:)*Gauss_kernel(i,:)'/Sum_Gauss(i);
end



figure, plot3(new_x,new_y,new_z,'r.');

x=new_x;
y=new_y;
z=new_z;
end

%plot3(new_x,new_y,new_z);
