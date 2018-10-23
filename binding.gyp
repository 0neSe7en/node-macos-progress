{
  "targets": [
    {
      "target_name": "macos-progress",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "src/node_progress.cc",
        "src/FileProgress.cc"
      ],
      "cflags": [ "-Wall", "-std=c++11" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "conditions": [
        ["OS=='mac'", {
          "libraries": [
            "-framework", "Foundation"
          ],
          "sources": ["src/Progress.mm"]
        }]
      ]
    }
  ]
}
