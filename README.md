# NoteReplacer

ドラム音源間のMIDIノートナンバーを変換するMIDIエフェクトプラグイン（VST3/AU対応）です。

## 概要

ドラム音源によって、各パーツ（キック、スネア、ハイハットなど）に割り当てられているMIDIノートナンバーは異なります。  
NoteReplacer は、あるドラム音源向けに打ち込んだMIDIデータを、別のドラム音源でそのまま再生できるようにノートナンバーをリアルタイムに変換します。

## 対応ドラムマップ

| ドラム音源 | 説明 |
|---|---|
| **GGD Modern & Massive** | GetGood Drums Modern & Massive |
| **GM** | General MIDI ドラムマップ |
| **Addictive Drums** | XLN Audio Addictive Drums |

## 変換パーツ一覧

- キック
- スネア（オープン / リム / サイドスティック）
- タム（1〜4）
- ハイハット（フットクローズ / クローズ / オープン / ペダルチック）
- ライド（チップ / ベル / クラッシュ）
- クラッシュ（左 / 右）
- チャイナ

## ビルド方法

### 必要環境

- [JUCE](https://juce.com/) （リポジトリ内の `JUCE/` に同梱）
- Visual Studio 2022 以降（Windows）
- [yaml-cpp](https://github.com/jbeder/yaml-cpp) （リポジトリ内の `yaml-cpp-master/` に同梱）

### 手順

1. `NoteReplacer.jucer` を Projucer で開く
2. 使用するIDEのエクスポーターを選択してプロジェクトを保存
3. 生成されたプロジェクトファイル（`Builds/VisualStudio2026/` など）をIDEで開いてビルド

## プロジェクト構成

```
Source/
  CommonDef.h          # ドラムマップの共通データ構造定義
  DrumMapGM.h/cpp      # GM ドラムマップ定義
  DrumMapManager.h/cpp # ドラムマップ変換ロジック
  YamlReader.h/cpp     # YAMLファイル読み込みユーティリティ
  PluginProcessor.h/cpp # MIDIエフェクト処理本体
  PluginEditor.h/cpp   # プラグインUI
```

## ライセンス

JUCE は [JUCE License](JUCE/LICENSE.md) に従います。  
yaml-cpp は MIT ライセンスです。
