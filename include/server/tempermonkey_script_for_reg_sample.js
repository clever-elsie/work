// ==UserScript==
// @name         AtCoder サンプル登録
// @namespace    http://tampermonkey.net/
// @version      1.2
// @description  Export sample inputs from AtCoder problems and send them to a local server.
// @author       CleverElsie
// @match        https://atcoder.jp/contests/*/tasks/*
// @grant        GM_xmlhttpRequest
// @require      https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js
// ==/UserScript==

(function () {
    'use strict';

    // ボタンを作成してページに追加
    function addButton() {
        const button = $('<button>')
            .text('サンプル登録')
            .css({
                position: 'fixed',
                bottom: '80px',
                right: '10px',
                padding: '10px 20px',
                backgroundColor: '#007bff',
                color: 'white',
                border: 'none',
                borderRadius: '5px',
                cursor: 'pointer',
                zIndex: 1000,
            })
            .on('click', handleButtonClick);

        $('body').append(button);
    }
    function showMSG(message, duration = 1000) {
        const isError = duration > 1000; // 1秒を超える場合はエラー扱い（赤色）
        const messageBox = $('<div>')
        .text(message)
        .css({
            position: 'fixed',
            bottom: '150px',
            right: '10px',
            padding: '10px 20px',
            backgroundColor: isError ? '#dc3545' : '#28a745', // 赤色または緑色
            color: 'white',
            borderRadius: '5px',
            boxShadow: '0 4px 6px rgba(0, 0, 0, 0.1)',
            zIndex: 1001,
            fontSize: '14px',
        })
        .hide();

        $('body').append(messageBox);
        messageBox.fadeIn(200); // 200msでフェードイン
        setTimeout(() => {
            messageBox.fadeOut(200, () => {
                messageBox.remove(); // 消えた後に要素を削除
            });
        }, duration);
    }
    // ボタンが押されたときの処理
    function handleButtonClick() {
        const samples = [];
        // h3タグの中身が「入力例」で始まるものを探す
        $('h3').filter(function () {
            return $(this).text().match(/^入力例/);
        }).each(function () {

            const match = $(this).text().match(/^入力例\s*(\d+)/); // 入力例の番号を抽出
            if (match) {
                const sampleId = parseInt(match[1], 10); // 番号を数値に変換
                const sampleText = $(this).nextAll('pre').first().text().trim(); // 次のpreのテキストを取得
                if (sampleText) {
                    samples.push({
                        id: sampleId,
                        sample_in: sampleText
                    });
                }
            }
        });

        if (samples.length === 0) {
            alert('No sample inputs found.');
            return;
        }

        // JSON形式で送信
        sendToServer(samples);
    }

    // サーバーにデータを送信
    function sendToServer(samples) {
        const url = 'http://localhost/conpro/sample_register'; // 送信先URL
        GM_xmlhttpRequest({
            method: 'POST',
            url: url,
            headers: {
                'Content-Type': 'application/json'
            },
            data: JSON.stringify(samples),
            onload: function (response) {
                if (response.status === 200) {
                    showMSG('Samples sent successfully!');
                } else {
                    showMSG('Failed to send samples: ' + response.statusText,2000);
                }
            },
            onerror: function () {
                showMSG('Error occurred while sending samples.',2000);
            }
        });
    }

    // 初期化処理
    addButton();
})();
