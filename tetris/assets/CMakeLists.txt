set(files "game_over.bmp" "legend.bmp")
foreach (file ${files})
    configure_file(${file} ${CMAKE_BINARY_DIR}/out/assets/${file} COPYONLY)
endforeach ()
