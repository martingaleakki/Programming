.test.saveTestCase:{[fname]
 oldpath:trim system "echo %CD%";
 path:"F:\\Programming\\TestCases";
 system ("cd ",path);
 save `$fname;
 system raze ("cd ",oldpath);
 }