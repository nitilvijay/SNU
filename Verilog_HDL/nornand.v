module nornand(a,b,y0, y1);
       input a,b;
       output y0,y1;
assign y0=~(a|b);
assign y1=~(a&b);
endmodule

module nornand_tb;
	reg a,b;
	wire y0,y1;
nornand l1(.a(a), .b(b), .y0(y0), .y1(y1));

initial
begin
	a=1'b0;
	b=1'b1;
end 

always #21 a=~a;
always #15 b=~b;
endmodule
