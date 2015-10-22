uses GraphABC;
var i:integer;xv1,yv1,xv2,yv2,xv3,yv3, xv0,yv0, xc,yc,x2,y2,x1,y1, x0,y0,x3,y3:integer;  gamma:real; 


procedure rotate(x0,y0:integer;x1,y1:integer;gamma:real;var x2,y2:integer);
var r:real; beta,alpha:real; 
begin
r:=sqrt(sqr(x1-x0)+sqr(y1-y0));
alpha:=arctan((x1-x0)/(y1-y0));
if (x1-x0)<0 then
alpha:=Pi-alpha;
beta:=gamma+alpha;
x2:=Round(r*cos(beta))+x0;
y2:=Round(r*sin(beta))+y0;
end;

begin

x1:=200;
y1:=100;
x2:=300;
y2:=300;
xc:=(x2+x1) div 2;
yc:=(y2+y1) div 2;

 
for i:=0 to 1000 do
begin
Clearwindow;
gamma:=(i*Pi)/180;
rotate(xc,yc,x1,y1,gamma,xv0,yv0);
rotate(xc,yc,x2,y2,gamma,xv1,yv1);
rotate(xc,yc,x1,y2,gamma,xv2,yv2);
rotate(xc,yc,x2,y1,gamma,xv3,yv3);
Line(xv0,yv0,xv1,yv1); 
Line(xv1,yv1,xv3,yv3); 
Line(xv3,yv3,xv2,yv2); 
Line(xv2,yv2,xv0,yv0);
sleep(50);
end;
end.