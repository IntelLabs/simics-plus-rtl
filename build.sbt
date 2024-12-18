// build.sbt
scalaVersion := "2.13.12"
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % "6.0.0" cross CrossVersion.full)
libraryDependencies += "org.chipsalliance" %% "chisel" % "6.0.0"

scalacOptions := Seq("-unchecked", "-deprecation", "-feature")
scalacOptions += "-language:reflectiveCalls"
