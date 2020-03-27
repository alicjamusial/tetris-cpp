set(files "game_over.bmp" "legend.bmp")
foreach(file ${files})
    configure_file(${file} ${file} COPYONLY)
endforeach()