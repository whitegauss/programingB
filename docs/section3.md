# Gnuplot and C++

提出予定のコード
- [c++](../fxy.cc)
- [gnuplot](../exp.gpl)

グラフ
<img width="720" height="504" alt="image" src="https://github.com/user-attachments/assets/2ae298ea-ce68-4f11-acc2-300da2c42f2c" />
## dataファイル

コンピュータ科学においてデータの扱いは用途に合わせて多様な進化を遂げてきた。
例えば階層性のあるjsonファイルやyaml、コンピュータと人間、どちらからみても可読性が高い（高くはない）xml、数字の区切れがわかりやすく、広く用いられているcsv（comma separated values）などがあげられる。

なぜかうちの大学ではdataファイルが用いられるが、これは主にスペース区切りのデータ形式である。利点は

- 人間が見て確認しやすい
- プログラムからも扱いやすい
- 余計な記号やヘッダーが不要でシンプル

欠点としては、データの意味（カラム名など）が分かりにくいことや、階層的なデータ表現には向かないことが挙げられる。

## 二重ループ

二重ループは回避することが望ましい。今回のデータ（1600程度）であれば問題ないが、扱うデータが増えると処理が遅くなってしまう。
授業では求められることはないだろうし、C++でそこがネックになることもそんなに考えられないが、Atcoderをpythonで挑戦しようと思っている人は注意。

**補足：**
C++では二重ループはグリッド状のデータ生成や画像処理などでよく使われる。  
ただし、データ量が大きくなる場合は、アルゴリズムの工夫や並列化（OpenMPなど）を検討することも重要。

## gnuplotの使用法

Gnuplotは、データファイルを可視化するための強力なツール。  
基本的な使い方は以下の通り。

### 基本的なコマンド例

```gnuplot
# 端末でgnuplotを起動し、以下のコマンドを入力

# データファイルを2次元でプロット
plot "fxy.data" using 1:2:3 with points palette

# 3次元プロット（サーフェス表示）
splot "fxy.data" using 1:2:3 with pm3d

# 軸ラベルの設定
set xlabel "x"
set ylabel "y"
set zlabel "f(x, y)"

# カラーバーの表示
set colorbox

# 出力ファイルの指定（例：PNG画像として保存）
set terminal png
set output "output.png"
splot "fxy.data" using 1:2:3 with pm3d
set output
```









