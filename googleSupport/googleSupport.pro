
  QT      +=  network widgets
  SOURCES =   main.cpp searchbox.cpp gsuggestcompletion.cpp
  HEADERS  =  searchbox.h gsuggestcompletion.h

  # install
  target.path = $$[QT_INSTALL_EXAMPLES]/network/googlesupport
  INSTALLS += target
