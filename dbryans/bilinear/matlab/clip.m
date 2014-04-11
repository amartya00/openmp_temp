function val = clip(x,a,b)
           %AVG subfunction
if(x <= a)
    val=a;
elseif (x>=b)
    val=b;
else
    val=x;
end