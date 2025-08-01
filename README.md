
my-first-PID-package
==============

TODO: input a short description of package my-first-PID-package utility here

# Table of Contents
 - [Package Overview](#package-overview)
 - [Installation and Usage](#installation-and-usage)
 - [Offline API Documentation](#offline-api-documentation)
 - [License](#license)
 - [Authors](#authors)




Package Overview
================

The **my-first-PID-package** package contains the following:

 * Libraries:

   * hello-static (static)

   * hello-shared (shared)

 * Applications:

   * hello-app


Installation and Usage
======================

The **my-first-PID-package** project is packaged using [PID](http://pid.lirmm.net), a build and deployment system based on CMake.

If you wish to adopt PID for your develoment please first follow the installation procedure [here](http://pid.lirmm.net/pid-framework/pages/install.html).

If you already are a PID user or wish to integrate **my-first-PID-package** in your current build system, please read the appropriate section below.


## Using an existing PID workspace

This method is for developers who want to install and access **my-first-PID-package** from their PID workspace.

You can use the `deploy` command to manually install **my-first-PID-package** in the workspace:
```bash
cd <path to pid workspace>
pid deploy package=my-first-PID-package # latest version
# OR
pid deploy package=my-first-PID-package version=x.y.z # specific version
```
Alternatively you can simply declare a dependency to **my-first-PID-package** in your package's `CMakeLists.txt` and let PID handle everything:
```cmake
PID_Dependency(my-first-PID-package) # any version
# OR
PID_Dependency(my-first-PID-package VERSION x.y.z) # any version compatible with x.y.z
```

If you need more control over your dependency declaration, please look at [PID_Dependency](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-dependency) documentation.

Once the package dependency has been added, you can use the following components as component dependencies:
 * `my-first-PID-package/hello-static`
 * `my-first-PID-package/hello-shared`

You can read [PID_Component](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-component) and [PID_Component_Dependency](https://pid.lirmm.net/pid-framework/assets/apidoc/html/pages/Package_API.html#pid-component-dependency) documentations for more details.
## Standalone installation

This method allows to build the package without having to create a PID workspace manually. This method is UNIX only.

All you need to do is to first clone the package locally and then run the installation script:
 ```bash
git clone https://github.com/jpcahueque/my-first-PID-package.git
cd my-first-PID-package
./share/install/standalone_install.sh
```
The package as well as its dependencies will be deployed under `binaries/pid-workspace`.

You can pass `--help` to the script to list the available options.

### Using **my-first-PID-package** in a CMake project
There are two ways to integrate **my-first-PID-package** in CMake project: the external API or a system install.

The first one doesn't require the installation of files outside of the package itself and so is well suited when used as a Git submodule for example.
Please read [this page](https://pid.lirmm.net/pid-framework/pages/external_API_tutorial.html#using-cmake) for more information.

The second option is more traditional as it installs the package and its dependencies in a given system folder which can then be retrived using `find_package(my-first-PID-package)`.
You can pass the `--install <path>` option to the installation script to perform the installation and then follow [these steps](https://pid.lirmm.net/pid-framework/pages/external_API_tutorial.html#third-step--extra-system-configuration-required) to configure your environment, find PID packages and link with their components.
### Using **my-first-PID-package** with pkg-config
You can pass `--pkg-config on` to the installation script to generate the necessary pkg-config files.
Upon completion, the script will tell you how to set the `PKG_CONFIG_PATH` environment variable for **my-first-PID-package** to be discoverable.

Then, to get the necessary compilation flags run:

```bash
pkg-config --static --cflags my-first-PID-package_<component>
```

```bash
pkg-config --variable=c_standard my-first-PID-package_<component>
```

```bash
pkg-config --variable=cxx_standard my-first-PID-package_<component>
```

To get the linker flags run:

```bash
pkg-config --static --libs my-first-PID-package_<component>
```

Where `<component>` is one of:
 * `hello-static`
 * `hello-shared`




Offline API Documentation
=========================

With [Doxygen](https://www.doxygen.nl) installed, the API documentation can be built locally by turning the `BUILD_API_DOC` CMake option `ON` and running the `doc` target, e.g
```bash
pid cd my-first-PID-package
pid -DBUILD_API_DOC=ON doc
```
The resulting documentation can be accessed by opening `<path to my-first-PID-package>/build/release/share/doc/html/index.html` in a web browser.

License
=======

The license that applies to the whole package content is **CeCILL**. Please look at the [license.txt](./license.txt) file at the root of this repository for more details.

Authors
=======

**my-first-PID-package** has been developed by the following authors: 
+ Juan Pablo CAHUEQUE (LS2N)

Please contact Juan Pablo CAHUEQUE (juan-pablo.cahueque@ls2n.fr) - LS2N for more information or questions.
