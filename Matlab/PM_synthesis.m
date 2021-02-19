clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')


fs = 96000;  
t = (0:1/fs:0.006-1/fs);
%carrier = zeros(1,11);
%alpha =(0:0.1:1);
f1 = 500;


phase = 0;

%Operator 3
beta = 0.5; %amplitude operator 3
delta = f1*5;
mod2 = sin(2*pi*delta*t+phase);

%Operator 2
alpha = 0.3; %amplitude operator 2
gamma = f1*3.5;
mod = sin(2*pi*gamma*t+pi*mod2*beta+phase);

%carrier
carriernonmod = sin(2*pi*f1*t);
carrier = sin(2*pi*f1*t + pi*mod*alpha);
%for i=1:1
%    carrier(i) = sin(2*pi*f1*t + pi*mod*alpha(i));
%end

figure('name','Time domain and frequency domain');
subplot(2,1,1);
plot(t,-carrier,'LineWidth',5);
hold on;
plot(t, mod/2);
%plot(t, carriernonmod,'--r','LineWidth',2);
title("op1(t)");
xlabel('Time(s)');
ylabel('Amplitude');
ylim( [-1.5 1.5] );

fftmaxfreq = 5000;
%fast fourier transform
y = fft(carrier/7.215, 20000); 
f = (0:length(y)-1)*fs/length(y);
subplot(2,1,2);
plot(f,abs(y)/48, 'LineWidth',3);
xlim([0 fftmaxfreq]);
xticks(0:500:fftmaxfreq);
ax = gca();
ax.XRuler.Exponent = 3;
title("Frequency domain(FFT) of op1(t)");
xlabel('Frequency(kHz)');
ylabel('Amplitude');
hold on;
grid;