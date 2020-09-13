--Name: Ravi Sahni
--Faclty No.: 17 COB 085
--Enrol. No.: GJ 7718

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity ripple4 is
Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
B : in STD_LOGIC_VECTOR (3 downto 0);
Cin : in STD_LOGIC;
S : out STD_LOGIC_VECTOR (3 downto 0);
Cout : out STD_LOGIC);
end ripple4;

architecture Basic of ripple4 is
component FA
Port ( A : in STD_LOGIC;
B : in STD_LOGIC;
Cin : in STD_LOGIC;
S : out STD_LOGIC;
Cout : out STD_LOGIC);
end component;

signal c1,c2,c3: STD_LOGIC;

begin
FA1: FA port map( A(0), B(0), Cin, S(0), c1);
FA2: FA port map( A(1), B(1), c1, S(1), c2);
FA3: FA port map( A(2), B(2), c2, S(2), c3);
FA4: FA port map( A(3), B(3), c3, S(3), Cout);

end Basic;

--writing entity & architecture for FA component
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
