name := "simics-chipyard"
version := "0.1"
scalaVersion := "2.13.10"

libraryDependencies ++= Seq(
  // "org.chipsalliance" %% "chisel" % "6.0.0",
  "edu.berkeley.cs" %% "chisel3" % "3.6.0",
  "edu.berkeley.cs" %% "rocketchip" % "1.6.+")

// addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % "6.0.0" cross CrossVersion.full)

scalacOptions := Seq("-unchecked", "-deprecation", "-feature")
scalacOptions += "-language:reflectiveCalls"
