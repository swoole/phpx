

libmpdec and libmpdec++ build instructions for Visual Studio
============================================================

   For all builds:  After a successful build, the static libraries, the dynamic
   libraries and the header files should be in the dist64 or dist32 directory.

   The unit tests attempt to download the official IBM test cases (text files).
   No executables are downloaded.


   64-bit release build
   --------------------

      # Clean the build directory if files from a previous build are present.
      vcdistclean.bat

      # Build the libraries.  Optionally use pgobuild64.bat instead of vcbuild64.bat
      # for a profile-guided optimization build.
      vcbuild64.bat

      # Run the unit tests.
      runshort.bat


   64-bit debug build
   ------------------

      # Clean the build directory if files from a previous build are present.
      vcdistclean.bat

      # Build the libraries.
      vcbuild64.bat /d

      # Run the unit tests.
      runshort.bat /d


   32-bit release build
   --------------------

      # Clean the build directory if files from a previous build are present.
      vcdistclean.bat

      # Build the libraries.  Optionally use pgobuild32.bat instead of vcbuild32.bat
      # for a profile-guided optimization build.
      vcbuild32.bat

      # Run the unit tests.
      runshort.bat


   32-bit debug build
   --------------------

      # Clean the build directory if files from a previous build are present.
      vcdistclean.bat

      # Build the libraries.
      vcbuild32.bat /d

      # Run the unit tests.
      runshort.bat /d





