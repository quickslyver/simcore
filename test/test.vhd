--------------------------------------------------------------------------------
--                                                                            --
--                      Copyright (C) 2009 INVIA                              --
--                                                                            --
--   All rights reserved. Reproduction in whole or part is prohibited         --
--      without the written permission of the copyright owner                 --
--                                                                            --
--------------------------------------------------------------------------------
-- Author: Sylvere TEISSIER - INVIA
-- Description: 
--------------------------------------------------------------------------------

entity test is
end entity ;

architecture rtl of test is
  signal i,j,k:integer:=10;
begin
  TEST:process(k)
  begin
  i<=k+k;
  j<=k+k;
  j<=k*2;
  end process;
end architecture rtl;
