# Modern CMake for C++

## 1: First Steps with CMake

- この本の[Github](https://github.com/PacktPublishing/Modern-CMake-for-Cpp-2E/tree/main/examples)でサンプルコードを公開している
- 下記コマンドラインで、実行できる
  - `<build tree>`は出力ディレクトリパス
  - `<source tree>`はソースコードがあるディレクトリパス

```shell
cmake -B <build tree> -S <source tree>
cmake --build <build tree>
```

- CMakeの優位性
  - 現代のコンパイラーやツールチェーン(製品を製作するのに使われるプログラム（ツール）の集合体)のサポート
  - Windows、Linux、MacOS、Cygwinなどをサポートする、Cross Platform
  - Visual Studio, Xcode, Eclipseなどの統合開発環境のプロジェクトファイルを自動生成できる
  - CMakeの操作は抽象化されていて、拡張しやすい
  - CMakeで作られたプロジェクトがたくさんあり、容易に自分のアプリにPluginできる
  - CMakeはテストやパッケージング、インストールをビルドプロセスの中に統合できる
  - 古いCmakeの機能は非推奨として、メンテされている
- CMakeは3つの工程で処理が進む
  - Configuration
    - ソースディレクトリを読み、出力ディレクトリを準備する
    - Cmakeはプロジェクトが事前に設定されているか確認したり、`CMakeCache.txt`といった設定ファイルを確認する
    - 初めに、どのような環境で開発されているか、コンパイラーが有効かどうか、リンカーやアーカイバーがインストールされているか確認する
    - 次に、`CMakeList.txt`の記載内容を実行する
    - `CMakeList.txt`にはプロジェクトの構造やターゲット、依存関係などを記述する
    - この工程中に、CMakeはシステムの詳細やプロジェクト設定、ログ、Tempファイルなど次工程で必要な情報を集め、その情報を`CMakeCache.txt`として生成する
  - Generation
    - BuildSystem生成する
    - BuildSystemは、GNUのMakeファイルや、統合開発環境のための、最適な設定ファイルである
  - Building
    - 最終成果物(実行ファイルやライブラリファイル)を生成するために、Build Toolを適用する

```cmake
cmake_minimum_required(VERSION 3.26)
project(Hello)
add_executable(Hello main.cpp)
```

```shell
cmake -B ./Build
cmake --build ./Build
```

- Windows環境でこれを実行したら、自動でVisualStudio2022が選ばれて、Solutionファイルが生成され、Debugビルドがされて、Hello.exeが生成された！

```
// BuildSystemの生成
C:\YM_ProgramData\Development\GitVisualStudio\CMake> cmake -B ./Build
// VS2022が自動で選ばれる
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.26100.
// MSVCはVisual C++
-- The C compiler identification is MSVC 19.42.34436.0
-- The CXX compiler identification is MSVC 19.42.34436.0
// CコンパイラがどのABI(アプリケーションバイナリインターフェース)を使用しているかを判断し、それをビルド設定に反映させる(Visual C++はABIをサポート)
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.42.34433/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.42.34433/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (7.4s)
-- Generating done (0.0s)
// Buildファイルが生成(VSではSolutionファイル？)
-- Build files have been written to: C:/YM_ProgramData/Development/GitVisualStudio/CMake/Build
```

```
// VSのProjectファイルをビルドしてくれた！
C:\YM_ProgramData\Development\GitVisualStudio\CMake> cmake --build ./Build
MSBuild のバージョン 17.12.12+1cce77968 (.NET Framework)

  1>Checking Build System
  Building Custom Rule C:/YM_ProgramData/Development/GitVisualStudio/CMake/CMakeLists.txt
  main.cpp
  Hello.vcxproj -> C:\YM_ProgramData\Development\GitVisualStudio\CMake\Build\Debug\Hello.exe
  Building Custom Rule C:/YM_ProgramData/Development/GitVisualStudio/CMake/CMakeLists.txt
```

- CMakeは5つのToolのセット
  - `cmake` : プロジェクトを設定したり、生成したりビルドをするメインの実行モジュール
  - `ctest` : テストを実行したり、テスト結果を報告したりするテストドライバー
  - `cpack` : インストーラーやソースパッケージを作ったりするパッケージングモジュール
  - `cmake-gui` : `cmake`周辺をラップするGUIツール
  - `ccmake` : `cmake`周辺をラップするコンソールベースのGUIツール

### CMakeのコマンドライン

- プロジェクトのビルドシステムの生成
  - プロジェクトをビルドするために必要な初めのステップは、ビルドシステムを作ること
  - ビルドシステムを作る方法は以下の3通りがある

```shell
// ソースとビルド結果ファイルを分けられるのでこれがオススメ
cmake [<options>] -S <source tree> -B <build tree>
```

- 本当は、対応したBuild Systemを作るために、ビルドツール(VisualStudioやXcodeやMakefile)を選ぶ必要があるが、通常は幸運なことに気にかける必要がない(CMakeが自動で選んでくれる)
- 指定するには、`CMAKE_GENERATOR`の環境変数を変更するか、下記の通り明示的にCommand実行する

```shell
cmake -G <generator name> -S <source tree> -B <build tree>
```

- VisualStudioといったいくつかのGeneratorは、Toolset(compiler)やプラットフォーム(compiler or SDK)の使用の詳細をサポートしている
- CMakeは`CMAKE_GENERATOR_TOOLSET`や`CMAKE_GENERATOR_PLATFORM`の環境変数をスキャンするが、明示的に特定のToolsetやPlatformを指定することができる

```shell
cmake -G <generator name> -T <toolset spec> -A <platform name> -S <source tree> -B <bulid tree>
```

- WindowsユーザーはIDE(VS)のビルドシステムを使いたいし、MacやLinuxユーザーはMakefileやNinjaを利用したい

```shell
// これで利用できるプラットフォームの一覧を確認できる
cmake --help
```

- CMakeはシステムの全ての種類の設定を確認し、CMakcCache.txtに保存するが、そのCacheに保存する振る舞いも設定することができる
- 私たちが自由に使える最初のオプションは、キャッシュされた情報を事前に入力する機能である。
- コマンドラインで設定する変数で大切なのは、Build Type(CMAKE_BUILD_TYPE)である
  - 1つの設定のGenerator(GNU MakeやNinja)はBuild Typeの設定が必要(DebugやReleaseやMinSizeRelやRelWithDebInfo)

```shell
cmake -S . -B ./Build -D CMAKE_BUILD_TYPE=Release
```  

- プロジェクトからBuild Treeを生成するオプションはたくさんあるが、混乱や見落としやすい。
- 開発者はプロジェクトに対してどのように相互作用するのかを設定することができ、`CMakePresets.json`でデフォルトの設定を提供することができる(16章参照)
- Build TreeをCleanする方法は下記の通り(Cleanって書いてるけど、やってみたら振る舞いがSolution/Projectファイルを再生成する振る舞いぽかった)

```shell
// Solution/Projectファイルの再生成っぽい振る舞い
cmake --fresh -S <source tree> -B <build tree>
```

- Build Treeができたら、次は実際にBuildして実行ファイルを作る！(Build方法は以下の通り)

```shell
cmake --build <build tree> [<options>] [-- <build-tool-options>]
//シンプルに
cmake --build <build tree>
```

- 並列ビルドも対応している p20
- 指定したVSのプロジェクトをビルドすることもできる

```shell
// <target>には、VSの.vsxprojファイルを指定する
cmake --build <build tree> --target <target1> --target <target2>
// --targetを-tにしてもOK
```

- Cleanする方法と、Cleanして通常ビルドする方法配下の通り

```shell
// Cleanするだけ
cmake --build <build tree> -t clean
// Cleanして通常ビルドする
cmake --build <build tree> --clean-first
```

- Releaseビルドする方法(指定しなければデフォルトはDebugビルドとなる)

```shell
// <cfg>にReleaseを指定する(ほかの文字を入れるとエラーになる)
cmake --build <build tree> --config <cfg>
// ReleaseをCleanするには
cmake --build <build tree> -t clean --config Release
```

- 実行ファイルを作る際のビルドで、コンパイラーから詳細なLog(VSと同等の出力)を出力する方法は以下の通り

```shell
cmake --build <build tree> --verbose
or
cmake --build <build tree> -v
```

- CMakeでインストールまで実行することができるが、Windows環境だとちょっと振る舞いがわからなかった。。。

```shell
cmake --install <build tree>
```

- CMakeのスクリプトを実行する方法
  - CMakeスクリプトを実行しても、CMakeの設定や生成ステージが走るわけではなく、キャッシュファイルが実行されるわけではない
  - `script.cmake`のファイル内に記述する

```shell
cmake [{-D <var>=<value>}...] -P <cmake script file> [-- <unparsed options>...]
```

```cmake
# script.cmakeの例(初めのバージョンの記述は書くことを推奨(cmakeの互換性のため))
cmake_minimum_required(VERSION 3.26.0)
message("Hello world")
file(WRITE Hello.txt "I am writing to a file")
```

- レアなケースだが、直でCMakeコマンドを実行する方法もあるが、一部のコマンドしか実行できない(詳細は、`cmake -E`を実行すと利用できるコマンドが表示される)

```shell
cmake -E <command> [<options>]
```

- `CTest`コマンドを利用すると、テストができる(詳細は11章)
- CPackコマンドラインを使うと、様々なプラットフォームに対して頒布用のモジュールを生成できる(installerやNuGetパッケージ、macOSバンドルなどなど)(詳細は１４章)

### CMakeのプロジェクトファイルやプロジェクトディレクトリについて

- Source Treeについて
  - c++ファイルや、CMakeプロジェクトファイルを格納する
    - `CMakeLists.txt`は必要
    - このフォルダのパスは`-S`で指定するので明確にすること
    - CMakeコードにこのSourceTreeの「絶対」パスをハードコーディングしないこと

- Build Treeについて
  - ビルドに必要なファイルをこのファイルに生成する(ソリューションファイルやキャッシュファイルなど)(`build root`や`binary tree`と呼ぶよ)
    - ビルドの設定ファイルなどのビルドツールが生成するファイルはここに生成されるよ
    - CMakeは、このBuildディレクトリをソースファイルとは別の場所に作ることを推奨する
    - `-B`オプションで指定するフォルダになるよ
    - このフォルダはGit登録しないほうがいいよ

- ListFileについて 
  - CMake言語を含んでいるファイルはListFileと呼び、`include()`や`find_package()`などで含めることができる。`xxx.cmake`というファイルであればよい

- Projectファイルについて(CMakeList.txt)
  - CMakeList.txtはSorceTreeの直下に置く必要があり、CMakeの実行フェーズに一番初めに実行される
  - `CMakeLists.txt`は最低限でも２つのコマンドを含める必要がある
    - `cmake_minimum_required(VERSION <x.xx>)`：CMakeの最低バージョンを記載し、過去バージョンのCMakeの振る舞いをサポートするように指示する
    - `project(<name> <OPTIONS>)`：`PROJECT_NAME`変数に格納するプロジェクトの名前を指定する。オプションについては、２章で解説
  - 開発が進むと、ソースを分けることがあるが、CMakeはCMakeLists.txtをsubフォルダ分けで管理することもサポートしている

```
myProject/CMakeList.txt
myProject/api/CMakeLists.txt
myProject/api/api.h
myProject/api/api.cpp
```

- この場合、直下のCMakeList.txtは下記のように記載すれば、apiフォルダ内のソースも含めることができる

```cmake
cmake_minimum_required(VERSION 3.26)
project(app)
message("Top level CMakeLists.txt")
add_subdirectory(api)
```

- トップレベルのCMakeList.txtは、依存関係、必須条件や開発環境を管理する
- `add_subdirectory(api)`によって、apiフォルダの中の`CMakeList.txt`を含めることができる

- Cacheファイル
  - キャッシュ変数はリストファイルから生成され、`CMakeCache.txt`に格納される
  - CMakeCache内の`EXTERNAL`はユーザーが編集してもよいが、`INTERNAL`はCMakeが管理するキャッシュ変数
  - このファイルは自身で、cmakeコマンドやGUIを利用して、編集することができる
  - CMakeCacheを消すことで、デフォルトの設定でプロジェクトをリセットすることができる

- Package定義ファイル
  - 14章(Installing and Packaging)で詳細を解説
  - Config-filesはライブラリバイナリーやヘッダーなどのヘルプツールをどのように使うかに関する情報が格納されている
  - ファイル名は、`<PackageName>-config.cmake`か`<PackageName>Config.cmake`とする
  - `find_package()`コマンドでパッケージを含める命令をする

- 生成されるファイルについて
  - 多くのファイルは生成過程でCMakeによってBuild Treeに生成されるが、それらは主導で編集すべきではない。CMakeは、CMake installアクションや、CTestやCPackの過程でその設定を利用する
    - `cmake_install.cmake`や`CTestTestfile.cmake`や`CPackConfig.cmake`を確認する

- Presetファイルについて
  - キャッシュ変数や生成器やBuild Treeなどを追加で設定する場合は、毎回主導で設定する以外に、Presetファイルを使うことで、設定が簡単になる
  - `cmake --list-presets`で現在のPresetを確認し、`cmake --preset=<preset> -S <source> -B <build tree>`でプリセットを反映することができる
  - Presetファイルは、以下のファイルで提供される
    - `CMakePresets.json`：プロジェクトの作者が公式のPresetとして提供する
    - `CMakeUserPresets.json`：プロジェクトの設定をカスタマイズしたいユーザーが提供するPresetファイル
  - Presetファイルは必ずしも必要ではないが、カスタマイズしたいなどの進んだケースでは有益(16章を参照)

## 2: The CMake Language

