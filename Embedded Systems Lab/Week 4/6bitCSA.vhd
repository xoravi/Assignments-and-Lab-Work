--Name: Ravi Sahni
--Faculty No.: 17 COB 085
--Enrol. No.: GJ 7718
--Assignment: Design and simulate a 6-bit Carry Select Adder.

--Full Adder
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity FA is
Port ( A : in STD_LOGIC;
B : in STD_LOGIC;
Cin : in STD_LOGIC;
S : out STD_LOGIC;
Cout : out STD_LOGIC);
end FA;

architecture Basic of FA is
begin
S <= A XOR B XOR Cin;
Cout <= (A AND B) OR (Cin AND (A OR B));
end Basic;

--2x1 MUX
library IEEE;
use IEEE.STD_LOGIC_1164.all;
 
entity mux2_1 is
port(
A,B : in STD_LOGIC;
Sel: in STD_LOGIC;
Z: out STD_LOGIC);
end mux2_1;
 
architecture bhv of mux2_1 is
begin
process(A,B,Sel)
begin
if Sel = '0' then
Z <= A;
else
Z <= B;
end if;
end process;
end bhv;

--6 Bit Carry Select Adder
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity CSA is
Port ( X : in STD_LOGIC_VECTOR (5 downto 0);
Y : in STD_LOGIC_VECTOR (5 downto 0);
CARRY_IN : in STD_LOGIC;
SUM : out STD_LOGIC_VECTOR (5 downto 0);
CARRY_OUT : out STD_LOGIC);
end CSA;
 
architecture Behavioral of CSA is
 
component FA
Port ( A, B, Cin : in STD_LOGIC;
S, Cout : out STD_LOGIC);
end component;
 
component mux2_1
port( A, B, Sel : in STD_LOGIC;
Z: out STD_LOGIC);
end component;
 
signal A,B,C0,C1: STD_LOGIC_VECTOR (5 DOWNTO 0);
begin
 
FA1: FA PORT MAP(X(0),Y(0),'0' ,A(0),C0(0));
FA2: FA PORT MAP(X(1),Y(1),C0(0),A(1),C0(1));
FA3: FA PORT MAP(X(2),Y(2),C0(1),A(2),C0(2));
FA4: FA PORT MAP(X(3),Y(3),C0(2),A(3),C0(3));
FA5: FA PORT MAP(X(4),Y(4),C0(3),A(4),C0(4));
FA6: FA PORT MAP(X(5),Y(5),C0(4),A(5),C0(5));
 
FA7: FA PORT MAP(X(0),Y(0),'1' ,B(0),C1(0));
FA8: FA PORT MAP(X(1),Y(1),C1(0),B(1),C1(1));
FA9: FA PORT MAP(X(2),Y(2),C1(1),B(2),C1(2));
FA10: FA PORT MAP(X(3),Y(3),C1(2),B(3),C1(3));
FA11: FA PORT MAP(X(4),Y(4),C1(3),B(4),C1(4));
FA12: FA PORT MAP(X(5),Y(5),C1(4),B(5),C1(5));
 
MUX1: mux2_1 PORT MAP(A(0),B(0),CARRY_IN,SUM(0));
MUX2: mux2_1 PORT MAP(A(1),B(1),CARRY_IN,SUM(1));
MUX3: mux2_1 PORT MAP(A(2),B(2),CARRY_IN,SUM(2));
MUX4: mux2_1 PORT MAP(A(3),B(3),CARRY_IN,SUM(3));
MUX5: mux2_1 PORT MAP(A(4),B(4),CARRY_IN,SUM(4));
MUX6: mux2_1 PORT MAP(A(5),B(5),CARRY_IN,SUM(5));
 
MUX7: mux2_1 PORT MAP(C0(5),C1(5),CARRY_IN,CARRY_OUT);
 
end Behavioral;
