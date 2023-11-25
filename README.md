# meta-dotnet-core
BitBake recipes to use the pre-built binaries provided by Microsoft for the following applications:

1. .Net Core 2.x, 3.x, (Use pre-honister branch)
2. .Net 5.x, 6.x, 7.x, and 8.x
3. ASP .Net Core 2.x, 3.x (Use pre-honister branch)
4. .Net 5.x, 6.x, 7.x, and 8.x
3. Visual Studio Remote Debugger (2017, 2019, and 2022)
  
## .Net Core 2.x, 3.x, and .Net 5.x, 6.x, 7.x, 8.x
This package will place the .Net Core runtime binaries into the image under /usr/share/dotnet. The package only supports X64 and ARM (32-bit and 64-bit) architectures. It does not build the runtime from source. It only pulls the publicly available binaries. Add this package by adding "dotnet-core" to the CORE_IMAGE_EXTRA_INSTALL line of your local.conf file.

## ASP .Net Core 2.x, 3.x, and .Net 5.x, 6.x, 7.x, 8.x
This package will place the ASP .Net Core runtime binaries into the image under /usr/share/dotnet. The package only supports X64 and ARM (32-bit and 64-bit) architectures. It does not build the runtime from source it only pulls the publicly available binaries. Add this package by adding "aspnet-core" to the CORE_IMAGE_EXTRA_INSTALL line of your local.conf file. This package also provides the .Net Core runtime environment so care should be taken to avoid adding this recipe and the .Net Core one (may add a PROVIDES virtual down the road).

## Visual Studio Remote Debugger
This package will place the vsdbg runtime binaries into the image under the root's home folder. The package only supports X64 and ARM (32-bit only) architectures for .Net Core 2.x and X64, ARM, and ARM64 for .Net Core 3.x on. It does not build these libraries from source. These binaries are not open source. Care should be taken to ensure the proprietary license can be adhered to for the given application. Add this package by adding "vsdbg" to the CORE_IMAGE_EXTRA_INSTALL line of your local.conf file.

Attaching to a process should work in Visual Studio, but you can also launch or attach to processes using json files. Below are examples of how this can
be done. I believe this can also be done in Visual Studio Code, but I haven't tested it. These are based on the tutorial given here:

https://github.com/Microsoft/MIEngine/wiki/Offroad-Debugging-of-.NET-Core-on-Linux---OSX-from-Visual-Studio

### Attaching to an Existing Process using a Launch Script

```
{
	"version": "0.2.0",
	// Specify a local application to use to connect in and run the command over ssh. Below is an example of using plink.exe (putty) on windows.
	"adapter": "C:\\putty\\plink.exe",
	// Specify the username and ip address to connect into. I also added logging, remove everything after '--heartbeat=1' to omit the logging.
	"adapterArgs": "myusername@10.15.32.5 -batch -T /home/root/.vs-debugger/vs2022/vsdbg --interpreter=vscode --heartbeat=1 --engineLogging=/mnt/share/vsdbgeng.log.txt | tee /mnt/share/vsdbg.log.txt",
	"configurations": [
		{
			"name": ".NET Core Remote Attach",
			"type": "coreclr",
			"request": "attach",
			// replace with the process id you want to attach to.
			"processId": 1283
		}
	]
}
```

### Running the Application in a New Process

```
{
	"version": "0.2.0",
	// Specify a local application to use to connect in and run the command over ssh. Below is an example of using plink.exe (putty) on windows.
	"adapter": "C:\\putty\\plink.exe",
	"adapterArgs": "myusername@10.15.32.5 -batch -T ~/.vs-debugger/vs2019/vsdbg --interpreter=vscode",
	"configurations": [
		{
			"name": ".NET Core Launch",
			"type": "coreclr",
			"cwd": "~/",
			"program": "/mnt/share/app_to_debug.dll",
			"request": "launch"
		}
	]
}
```

## Dependencies
This layer depends on:

URI | Layers
--- | ------
git://git.openembedded.org/bitbake | 
git://git.openembedded.org/openembedded-core | meta 
git://git.yoctoproject.org/meta | meta 
git://git.openembedded.org/meta-openembedded | meta-oe 
git://git.openembedded.org/meta-openembedded | meta-python 
git://git.openembedded.org/meta-openembedded | meta-networking 

## Patches
Please submit any patches against this layer using pull requests in github or open up an issue.

## Table of Contents
1. Adding the meta-dotnet-core to your build
2. Curl Configuration and Modification (pre-honister branch only)
3. Specific Versions

### 1. Adding the meta-dotnet-core to your build
In order to use this layer, you need to make the build system aware of it.

Assuming the meta-dotnet-core layer exists at the top-level of your yocto build tree, you can add it to the build system by adding the location of the layer to bblayers.conf, along with any other layers needed. e.g.:

```
  BBLAYERS ?= " \
    /path/to/yocto/meta \
    /path/to/yocto/meta-poky \
    /path/to/yocto/meta-yocto-bsp \
    /path/to/yocto/meta-dotnet-core \
    "
```

### 2. Curl Configuration and Modification (pre-honister branch only)
The following must be added to your local.conf file to enable specific support that is required in curl for 2.x and 3.x versions of .Net Core:

```
  PACKAGECONFIG_pn-curl = "vers krb5 ssl zlib ipv6"
```

NOTE: this layer will modify the curl library to contain the CURL_OPENSSL_3 versioned symbols. If .Net 5.x or above is targetted then this bbappend can be disabled.

### 3. Specific Versions
You can select a specific version by adding the following line to your local.conf file:

```
PREFERRED_VERSION_<package name> = "<version>"
```
  
For example:

```
PREFERRED_VERSION_dotnet-core = "5.0.0"
```


