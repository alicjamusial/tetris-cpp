//
// Created by Alicja on 2020-03-06.
//

#pragma once
#include "Board.hpp"
#include "GraphicInterface.hpp"
#include <random>

namespace game
{
    enum GameState
    {
        Game,
        GameOver
    };

    class Gameplay
    {
    public:
        Gameplay(std::shared_ptr<GraphicInterface> &pGraphicInterface);

        void InitGameplay();
        void DrawScene();
        void CreateNewPiece();

        // current falling piece
        int16_t currentPiece{}, currentRotation{};
        Point currentPoint{};

        void CallAction(uint16_t key);

        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void MoveBottom();
        void Rotate();
        void Fall();

        void RestartGame();

    private:
        GameState _gameState{Game};

        std::map<uint16_t, void (Gameplay::*)()> _gameAction;

        std::random_device _randomDevice;
        std::mt19937 _engine;
        std::uniform_int_distribution<int> _distribution;

        int16_t _nextPiece{}, _nextRotation{};
        Point _nextPoint{};

        std::unique_ptr<Board> _board;
        std::shared_ptr<GraphicInterface> _graphicInterface;

        void DrawPiece(Point point, int16_t piece, int16_t rotation);

        void DrawBoardAndLegend();

        void CheckIfGameOver();

        void StorePiece();

        int16_t GetRand(int16_t prescaler = 1);
        static int16_t GetNextRotation(int16_t rotation);
    };
}
