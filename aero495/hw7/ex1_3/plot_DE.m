out1 = zeros(1, 100);
out2 = zeros(1, 100);
out3 = zeros(1, 100);
out4 = zeros(1, 100);

for j = 1 : 100
   out1(j) = 0.5*(exp((2*i-0.1)*j/10) + exp((-2i-0.1)*j/10));
   out2(j) = 0.5*i*(exp((2*i-0.1)*j/10) - exp((-2i-0.1)*j/10));
   out3(j) = cos(2*j/10)*exp(-0.1*j/10);
   out4(j) = sin(2*j/10)*exp(-0.1*j/10);
end


