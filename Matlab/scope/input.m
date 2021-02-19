clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')

%Gamma 2 beta 0
file = 'u1.CSV';
T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);
figure('name', 'gamma = 2, beta = 0');

subplot(2,1,2);
plot(x+0.06, y);
ax = gca();
ax.XRuler.Exponent = -3; %set exponent of x axis
title("U1(t)");
xlabel('Time(s)');
ylabel('Amplitude(V)');
set(gcf,'color','w');
set(gca,'FontSize',20)
xlim([0 0.06])

grid on;

wavefile = 'u3.CSV';
table = readtable(wavefile);
array = table2array(table);
sz1 = size(array);
x_1 = array(1:sz1(1)/2,1);
y_1 = array(1:sz1(1)/2,2);

subplot(2,1,1);
plot(x_1+0.06,y_1,'LineWidth',2);
ax = gca();
ax.XRuler.Exponent = -3; %set exponent of x axis
title("U3(t) with U2(t) = -10V");
xlabel('Time(s)');
ylabel('Amplitude(v)');
set(gcf,'color','w');
set(gca,'FontSize',20);
%g2 d4
%g3 d6
%g5 d1





