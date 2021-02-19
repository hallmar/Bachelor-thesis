clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')


fs = 192000; %set sample rate  
t = (0:1/fs:0.2-1/fs); %create time vector with sample rate


%Lots of miscallenous calculation stuff for 3d plot
alpha =(0:0.1:1); %create an alpha vector
sz = size(alpha); %get size of alpha vector
alphasize=sz(2); %get value from the sz vector
sz = size(t); 
tsize=sz(2);

%populate alphabig so that it has same dimension as op1
alphabig = zeros(alphasize,tsize);
for i=1:alphasize
    alphabig(i,1:tsize) = alpha(i);
end
op1 = zeros(alphasize,tsize);
f1 = 500;


%Operator 3
beta = 0.5; %amplitude operator 3
delta = f1*1;
op3 = sin(2*pi*delta*t);

%Operator 2
%alpha = 0.3; %amplitude operator 2
gamma = f1*5;
op2 = sin(2*pi*gamma*t+pi*op3*beta);

%op1
op1nonmod = sin(2*pi*f1*t);


%subplot(2,1,1);
for i=1:alphasize    
    op1(i,1:tsize) = sin(2*pi*f1*t + pi*op2*alpha(i)); 
end
op12 = sin(2*pi*f1*t + pi*op2*alpha(6));
%plot(t, op2/2);
%plot(t, op1nonmod,'--r','LineWidth',2);
% plot3(t, alphabig, -op1,'LineWidth',3);


%---------------3d plot------------------
figure('name','3 dimensional plot of op1(t)');
mesh(t, alphabig, -op1); %make a 3d mesh plot
colormap([0  0  0]) %make mesh black and white
view(-9,24) %select viewing angle
%hold on;

title("op1(t)");
xlabel('Time(s)');
ylabel('Alpha');
zlabel('Amplitude');

ylim( [0 1] );
zlim( [-1.5 1.5] );

set(gcf,'color','w');
set(gca,'FontSize',20)


%---------------fourier and non 3d------------------
figure('name','Fourier and time plot of op1(t)');;

%---------------operator 1------------------
subplot(2,1,1);
plot(t,-op12,'LineWidth',3);
hold on;
%plot(t, op2/2);
%plot(t, op1nonmod,'--r','LineWidth',2);
title("op1(t)");
xlabel('Time(s)');
ylabel('Amplitude');
ylim( [-1.5 1.5] );
xlim( [0 0.006]);
set(gcf,'color','w');
set(gca,'FontSize',20)

%---------------fourier------------------
fftmaxfreq = 20000; %set max frequency
%fast fourier transform
y = fft(op12,20000); %do a discrete fast fourier transform with 
                            %20000 points
f = (0:length(y)-1)*fs/length(y); %make an f vector

subplot(2,1,2);
y_abs = abs(y); %scale y so that amplitude of 1 in t domain corresponds
                    %to 1 in f domain
y_max = max(y_abs);
y_scale = y_abs/y_max;

plot(f,y_scale, 'LineWidth',3); %plot fourier transform

xlim([0 fftmaxfreq]); 
xticks(0:500:fftmaxfreq);
ax = gca();
ax.XRuler.Exponent = 3; %set exponent of x axi
title("Frequency domain(FFT) of op1(t)");
xlabel('Frequency(kHz)');
ylabel('Amplitude');
hold on;

% yyaxis right
% plot(f, angle(y)*(180/pi));
% ylabel('Phase(degrees)');
 set(gcf,'color','w');
 set(gca,'FontSize',20)
% grid;

