load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "APPLib",
  visibility = ["//visibility:public"],
  hdrs = glob(["**/*.h"]),
  srcs = glob(["pokedex.cpp"]),
)

# cc_library(
#   name = "APP_src",
#   visibility = ["//visibility:public"],
#   srcs = glob(["pokedex.cpp"]),
#   deps = ["//Inc:APPLib"],
# )