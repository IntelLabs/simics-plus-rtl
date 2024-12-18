// build.sbt
scalaVersion := "2.13.15"
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % "6.6.0" cross CrossVersion.full)
libraryDependencies += "org.chipsalliance" %% "chisel" % "6.6.0"

scalacOptions := Seq("-unchecked", "-deprecation", "-feature")
scalacOptions += "-language:reflectiveCalls"
