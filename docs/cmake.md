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
- CMakeはシステムの全ての種類の設定を確認し、CMakcCache.txtに保存するが、そのCacheに保存する振る舞いも設定することができる
- 私たちが自由に使える最初のオプションは、キャッシュされた情報を事前に入力する機能である。
- コマンドラインで設定する変数で大切なのは、Build Type(CMAKE_BUILD_TYPE)である
  - 1つの設定のGenerator(GNU MakeやNinja)はBuild Typeの設定が必要(DebugやReleaseやMinSizeRelやRelWithDebInfo)

```shell
cmake -S . -B ./Build -D CMAKE_BUILD_TYPE=Release
```  

