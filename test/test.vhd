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
  signal i,j:integer:=10;
begin
  
  i<=i+1;
  j<=j+1;

end architecture rtl;
